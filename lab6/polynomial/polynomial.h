
#ifndef LAB6_POLYNOMIAL_H
#define LAB6_POLYNOMIAL_H
#include "vector/vector.h"
#include <iostream>
#include <cstring>
#include <algorithm>

class Term{
private:
    int ratio;
    int indicator;
    friend class Polynomial;
public:
    Term(int _ratio = 0, int _indicator = 0) : ratio(_ratio), indicator(_indicator) {}
    ~Term(){};
    const int getratio(){return ratio;};
    const int getindicator(){return indicator;};
    void setratio(int _ratio){this->ratio=_ratio;};
    void setindicator(int _indicator){this->indicator=_indicator;};
    friend Term &operator+(Term &s1,Term &s2){
        static Term res;
        res.ratio=s1.ratio+s2.ratio;
        res.indicator=s1.indicator;
        return res;
    };
    void readTerm(const char*, int&);
    char* delete_readTerm(char*,int&,bool&);

};


void Term::readTerm(const char* text, int &size){
    int index=0;
    int _ratio=0;
    int _indicator=0;
    bool breakpoint=true;
    bool pointer_x=false;
    bool index_minus=false;
    bool index_space=false;
    while (text[index]==' ' or text[index]=='+'){
        index++;
    }
    if(text[index]=='-'){
        index_minus=true;
        index++;
    }
    while(breakpoint) {
        while (text[index] != '+' and text[index]!='-' and  text[index] != '\0') {
            if (text[index]!='x' and  !pointer_x and !index_minus and text[index]!=' '){
                _ratio=_ratio*10+ (text[index]-'0');
            }
            else if(text[index]!='x' and  !pointer_x and index_minus and text[index]!=' '){
                while(!index_space){
                    if(text[index]!=' '){index_space=true;}
                    else{index++;}
                }
                if(text[index]=='x'){
                    pointer_x=true;
                    _ratio=-1;
                }
                else {
                    _ratio = _ratio * 10 + (text[index] - '0');
                    _ratio = -_ratio;
                }
            }
            else if(text[index]!='x' and text[index]!='^' and text[index]!=' ' and pointer_x){
                _indicator=_indicator*10+(text[index]-'0');
            }
            else if(text[index]!=' '){pointer_x=true;}
            index++;
        }
        breakpoint=false;

    }

    ratio=_ratio;
    if(_indicator==0 and pointer_x){indicator=_indicator+1;}
    else{indicator=_indicator;}

    size=index;
}
char* Term::delete_readTerm(char *text, int &size, bool &breakpoint) {
    if (text == nullptr) {
        breakpoint = false;
        return nullptr;
    }

    if (strlen(text) == size) {
        breakpoint = false;
        delete[] text; // Освобождаем память, выделенную для старой строки
        return nullptr;
    } else {
        int new_size = strlen(text) - size;
        if (new_size < 0) {
            new_size = 0;
        }
        char *new_text = new char[new_size + 1];

        for (int i = size; i < strlen(text); i++) {
            new_text[i - size] = text[i];
        }
        new_text[new_size] = '\0';
        delete[] text;
        if (new_size == 0) {
            breakpoint = false;
        }

        return new_text;
    }
}




class Polynomial{
private:
    bool order_;
    vector<Term> poly;
    int degree;
public:
    Polynomial(){
        degree=0;
    };
    Polynomial(int n){
        degree=0;
    };
    Polynomial(Term temp){
        degree=std::max(degree,temp.getindicator());
    };
    Polynomial(Polynomial &ary){
        poly=ary.poly;
        degree=ary.degree;
    }
    void clear(){
        poly.clear();
    }
    friend std::istream &operator>>(std::istream &in, Polynomial&);
    friend std::ostream &operator<<(std::ostream &out,  Polynomial&);
    Polynomial sum(bool order);
    friend Polynomial &operator+(Polynomial &v1,Polynomial &v2);
    friend Polynomial &operator*(Polynomial &v1, Polynomial &v2);
    friend void parse(Polynomial &ary, char* text);
    Polynomial &operator=(const Polynomial &v)= default;
    const Polynomial &operator+=(Polynomial &v){

        Polynomial Term;
        Term.order_=v.order_;
        Term.degree=std::max(degree,v.degree);

        for(int i=0;i<v.poly.getsize();i++){
            Term.poly.add_element(v.poly[i]);
        }
        for(int i=0;i<poly.getsize();i++){
            Term.poly.add_element(poly[i]);
        }
        Term=Term.sum(order_);

        *this=Term;
        return *this;
    };

    Polynomial &operator*=(Polynomial &v){
        Polynomial term;
        term.degree=degree+v.degree;
        term.order_=v.order_;
        for (int i = 0; i < poly.getsize(); ++i) {
            for (int j = 0; j < v.poly.getsize(); ++j) {
                int newRatio = poly[i].getratio() * v.poly[j].getratio();
                int newIndicator = poly[i].getindicator() + v.poly[j].getindicator();
                term.poly.add_element({newRatio, newIndicator});
            }
        }
        term=term.sum(term.order_);
        *this=term;
        return *this;
    };
};

void parse(Polynomial &ary, char* text){
    Term temp;
    bool breakpoint=true;
    int size=0;
    while(breakpoint){
        temp.readTerm(text,size);
        ary.poly.add_element(temp);
        text=temp.delete_readTerm(text,size,breakpoint);
        if(ary.degree<temp.getindicator()){
            ary.degree=temp.getindicator();
        }
    }

}

std::istream &operator>>(std::istream &in, Polynomial &ary){

    char* text=new char[200];
    in.getline(text,200);
    parse(ary,text);
    bool order;
    in>>order;
    in.ignore();
    ary.order_=order;
    ary=ary.sum(ary.order_);
    return in;
}

std::ostream &operator<<(std::ostream &out,Polynomial &ary){
    for (int i=0;i<ary.poly.getsize();i++){
        int _ratio=ary.poly[i].getratio();
        int _indicator=ary.poly[i].getindicator();
        if(i==0) {
            if ((_ratio==1 or _ratio == -1) and _indicator != 0 and _indicator != 1) {
                if (_ratio==1) {
                    out << "x^" << _indicator << " ";
                } else {
                    out << "- x^" << _indicator << " ";
                }
            } else if ((_ratio==1 or _ratio == -1) and _indicator==1) {
                if (_ratio == 1) {
                    out << "x" << " ";
                } else {
                    out << "- x" << " ";
                }
            } else if (_indicator == 0) {
                out << _ratio << " ";
            } else if (_indicator == 1) {
                if(_ratio<0) {
                    out << _ratio << "x" << " ";
                }
            } else {
                out <<_ratio<< "x^" << _indicator << " ";
            }
        }
        else if(i==ary.poly.getsize()-1){
            if ((_ratio==1 or _ratio == -1) and _indicator != 0 and _indicator != 1) {
                if (_ratio==1) {
                    out << "+ x^" << _indicator << "\n";
                } else {
                    out << "- x^" << _indicator << "\n";
                }
            } else if ((_ratio==1 or _ratio == -1) and _indicator == 1) {
                if (_ratio==1) {
                    out << "+ x" << "\n";
                } else {
                    out << "- x" << "\n";
                }
            } else if (_indicator == 0) {
                if(_ratio<0) {
                    out <<"- "<< abs(_ratio) << "\n";
                }
                else{
                    out <<"+ "<<_ratio << "\n";
                }
            } else if (_indicator == 1) {
                if(_ratio<0) {
                    out <<"- "<< abs(_ratio) << "x" << "\n";
                }
                else{
                    if(_ratio==0){out << "+ x" << "\n";}
                    else{out <<"+ "<<_ratio << "x" << "\n";}
                }
            } else {
                if(_ratio<0) {
                    out <<"- "<<abs(_ratio) << "x^" << _indicator << "\n";
                }
                else{
                    if(_ratio==0){out << "+ x^" << _indicator << "\n";}
                    else{out <<"+ "<<_ratio << "x^" << _indicator << "\n";}
                }
            }
        }
        else{
            if ((_ratio==1 or _ratio == -1) and _indicator != 0 and _indicator != 1) {
                if (_ratio==1) {
                    out << "+ x^" << _indicator << " ";
                } else {
                    out << "- x^" << _indicator << " ";
                }
            } else if ((_ratio==1 or _ratio == -1) and _indicator == 1) {
                if (_ratio==1) {
                    out << "+ x" << " ";
                } else {
                    out << "- x" << " ";
                }
            } else if (_indicator == 0) {
                if(_ratio<0) {
                    out <<"- "<< abs(_ratio) << " ";
                }
                else{
                    out <<"+ "<<_ratio << " ";
                }
            } else if (_indicator == 1) {
                if(_ratio<0) {
                    out <<"- "<< abs(_ratio) << "x" << " ";
                }
                else{
                    if(_ratio==0){out <<"+ "<< "x" << " ";}
                    else{out <<"+ "<<_ratio << "x" << " ";}

                }
            } else {
                if(_ratio<0) {
                    out <<"- "<<abs(_ratio) << "x^" << _indicator << " ";
                }
                else{
                    if(_ratio==0){out <<"+ "<< "x^" << _indicator << " ";}
                    else{out <<"+ "<<_ratio << "x^" << _indicator << " ";}

                }
            }
        }
    }
    return out;
}

Polynomial Polynomial::sum(bool order) {
    order = order_;
    vector<Term> new_vec;
    for(int indicator = 0; indicator < degree+1; ++indicator) {
        int _ratio = 0;
        for(int i = 0; i < poly.getsize(); ++i) {
            if(poly[i].getindicator() == indicator) {
                _ratio += poly[i].getratio();
            }
        }
        if(_ratio != 0) {
            new_vec.add_element({_ratio, indicator});
        }
    }
    Polynomial new_poly;
    new_poly.degree=degree;
    if(order){
        new_poly.poly=new_vec.reverse();
    }// TODO: reverse vector<Term> reverse() ... return *this
    else{
        new_poly.poly=new_vec;
    }
    return new_poly;
}


Polynomial &operator+(Polynomial &v1, Polynomial &v2) {
    static Polynomial result;
    result.order_ = v1.order_;
    result.degree = std::max(v1.degree, v2.degree);


    for (int i = 0; i <v1.poly.getsize() ; ++i) {
        result.poly.add_element(v1.poly[i]);
    }
    for (int i = 0; i < v2.poly.getsize(); ++i) {
        result.poly.add_element(v2.poly[i]);
    }


    result.poly = result.sum(result.order_).poly;

    return result;
}

Polynomial &operator*(Polynomial &v1, Polynomial &v2){
    static Polynomial result;
    result.order_ = v1.order_;
    result.degree = v1.degree + v2.degree;

    for (int i = 0; i < v1.poly.getsize(); ++i) {
        for (int j = 0; j < v2.poly.getsize(); ++j) {
            int newRatio = v1.poly[i].getratio() * v2.poly[j].getratio();
            int newIndicator = v1.poly[i].getindicator() + v2.poly[j].getindicator();
            result.poly.add_element({newRatio, newIndicator});
        }
    }


    result = result.sum(result.order_);

    (result.order_) ? result.degree = result.poly[0].getindicator() : result.order_=result.poly[result.poly.getsize()-1].getindicator();

    return result;

}


#endif //LAB6_POLYNOMIAL_H

