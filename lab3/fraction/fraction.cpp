#include "fraction.h"

std::istream &operator>>(std::istream &in, fraction &ary) {
    char *number = new char[20];
    in.getline(number, 20);
    fraction* p = &ary;
    readnumber(p, number);
    return in;
}

std::ostream &operator<<(std::ostream &out, fraction &ary) {
    int numer = ary.getnumer();
    int integer=0;
    if(ary.getdenom()==0){
        out<<"Error"<<"\n";
        return out;
    }
    if (numer==0 and ary.getdenom()==1){
        out<<"0"<<"\n";
        return out;
    }
    if(numer<0 and abs(numer)>ary.getdenom()) {
        integer = numer / ary.getdenom();
        numer -= integer * ary.getdenom();
        numer=-numer;
    }
    else{
        integer = numer / ary.getdenom();
        numer -= integer * ary.getdenom();
    }
    int gcd=std::__gcd(abs(numer),ary.getdenom());
    if (integer == 0) {
        out << numer/gcd << "/" << ary.getdenom()/gcd << "\n";
        return out;
    } else {
        if (numer==0){
            out<<integer<<"\n";
            return out;
        }
        else {
            out << integer << ' ' << numer / gcd << "/" << ary.getdenom() / gcd << "\n";
            return out;
        }
    }

}


fraction::fraction(double dbl) {
    int integer=static_cast<int>(dbl);
    dbl= round((dbl-integer)*100000.00)/100000.00;
    int number;
    int counter=0;
    while (true){
        dbl*=10;
        counter++;
        number=static_cast<int>(dbl);
        if (dbl-number==0){break;}
    }
    denominator=pow(10,counter);
    numerator=integer*denominator+dbl;
    int gcd=std::__gcd(abs(numerator),denominator);
    numerator/=gcd;
    denominator/=gcd;

}

fraction::fraction(const char* fractionString) {
    int integer=0;
    int index=0;
    for(int i=0;i< strlen(fractionString);i++){
        if(fractionString[i]==' '){
            index=i;
            break;
        }
    }

    if (index!=0) {
        std::sscanf(fractionString, "%d %d/%d", &integer, &numerator, &denominator);
    }
    else{
        std::sscanf(fractionString, "%d/%d",&numerator,&denominator);
    }
    if (integer<0 and numerator>0){
        numerator+=abs(integer)*denominator;
        numerator=-numerator;
    }
    else if(integer>0 and numerator<0){
        integer=-integer;
        numerator=-numerator;
        numerator+=abs(integer)*denominator;
        numerator=-numerator;

    }
    else{
        integer=-integer;
        numerator=-numerator;
        numerator+=abs(integer)*denominator;
    }
    if (numerator != 0) {
        int gcd = std::__gcd(abs(numerator), denominator);
        if(integer<0) {
            numerator /= gcd;
            denominator /= gcd;
        }
    } else {
        denominator = 1;
    }
}

fraction::fraction(const fraction &other) {
    this->numerator=other.numerator;
    this->denominator=other.denominator;
}

fraction::fraction(int num, int denom) {
    int _gcd = std::__gcd(abs(num), denom);
    if (_gcd!=0) {
        this->numerator = num / _gcd;
        this->denominator = denom / _gcd;
    }

}

fraction operator+(const double lhs, const fraction &rhs) {
    fraction temp=lhs;
    temp.numerator=temp.numerator*rhs.denominator+rhs.numerator*temp.denominator;
    temp.denominator*=rhs.denominator;
    return temp;
}

fraction operator +(const int lhs,const fraction &rhs){
    fraction out(rhs.numerator,rhs.denominator);
    out.numerator+=lhs*out.denominator;
    return out;
}



int split_space(char *text) {
    int ind;
    for (int i = 0; i < strlen(text); i++) {
        if (text[i] == ' ') {
            ind = i;
            return ind;
        }
    }
    return 0;
}

int split_slash(char *text) {
    int ind;
    for (int i = 0; i < strlen(text); i++) {
        if (text[i] == '/') {
            ind = i;
            return ind;
        }
    }
    return 0;
}

void readnumber(fraction *&ary, char *number) {
    bool space = false;
    bool minus_integer=false;
    bool minus_numer=false;
    int ind_space;
    int ind_slash = split_slash(number);
    if (split_space(number) != 0) {
        space = true;
        ind_space = split_space(number);
    }
    if(number[0]=='-'){minus_integer=true;}
    if (!space and number[0]=='-' and ind_slash!=0){minus_numer=true;}
    int integer = 0;
    int numerator = 0;
    int denominator = 0;

    if(ind_space==0 and ind_slash==0 and !(minus_integer)){
        for(int i=0;i< strlen(number);i++){
            integer = integer * 10 + (number[i] - '0');
        }
    }
    else if(ind_space==00 and ind_slash==0 and minus_integer){
        for(int i=1;i< strlen(number);i++){
            integer = integer * 10 + (number[i] - '0');
        }
        integer=-integer;
    }


    if (space) {
        if (minus_integer) {
            for (int i = 1; i < ind_space; i++) {
                integer = integer * 10 + (number[i] - '0');
            }
            integer=-integer;
        }
        else{
            for (int i = 0; i < ind_space; i++) {
                integer = integer * 10 + (number[i] - '0');
            }
        }
        for (int i = ind_space + 1; i < ind_slash; i++) {
            numerator = numerator * 10 + (number[i] - '0');
        }
        for (int i = ind_slash + 1; number[i] != '\0'; i++) {
            denominator = denominator * 10 + (number[i] - '0');
        }
    } else {
        if (minus_numer) {
            for (int i = 1; i < ind_slash; i++) {
                numerator = numerator * 10 + (number[i] - '0');
            }
            numerator=-numerator;
        }
        else{
            for (int i = 0; i < ind_slash; i++) {
                numerator = numerator * 10 + (number[i] - '0');
            }
        }
        for (int i = ind_slash + 1; number[i] != '\0'; i++) {
            denominator = denominator * 10 + (number[i] - '0');
        }
    }
    if (integer<0){
        numerator+=abs(integer)*denominator;
        numerator=-numerator;
    }
    else if(integer==0 and minus_integer==true){
        numerator+=integer*denominator;
        numerator=-numerator;
    }
    else if(integer!=0 and denominator==0){
        numerator=integer;
        denominator=1;
    }
    else{
        numerator+=integer*denominator;
    }
    int _gcd = std::__gcd(abs(numerator), denominator);
    numerator /= _gcd;
    denominator /= _gcd;
    ary[0].setAll(numerator, denominator);
}


