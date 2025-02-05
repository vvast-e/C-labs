#ifndef LAB3_FRACTION_H
#define LAB3_FRACTION_H
#include <cmath>
#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>
#include <cstdio>


class fraction {
private:
    int numerator;
    int denominator;
public:
    fraction(){
        numerator=0;
        denominator=1;
    }
    fraction(int num, int denom);
    fraction(const char* text);
    fraction(const fraction &);
    fraction(double);
    ~fraction(){};


    fraction operator +(const fraction &other){
        fraction temp;
        int num=this->numerator;
        int denom=this->denominator;
        temp.denominator=denom*other.denominator;
        temp.numerator=num*other.denominator+other.numerator*denom;

        return temp;
    }

    fraction operator +=(const fraction &other){
        this->numerator=this->numerator*other.denominator+other.numerator*this->denominator;
        this->denominator*=other.denominator;
        fraction temp(this->numerator,this->denominator);
        return temp;
    }
    fraction operator +(const double dbl){
        fraction temp=dbl;
        int numer;
        int denom;
        numer=this->numerator;
        denom=this->denominator;
        numer=numer*temp.denominator+temp.numerator*denom;
        denom*=temp.denominator;
        fraction out(numer,denom);
        return out;
    }

    friend fraction operator+(const double lhs, const fraction &rhs);
    friend fraction operator+(const int lhs,const fraction &rhs);

    fraction operator +=(const double dbl){
        fraction temp=dbl;
        this->numerator=this->numerator*temp.denominator+temp.numerator*this->denominator;
        this->denominator*=temp.denominator;
        fraction out(this->numerator,this->denominator);
        return out;
    }


    fraction operator +(const int num){
        int numer=this->numerator;
        int denom=this->denominator;
        numer+=num*denom;
        fraction temp(numer,denom);
        return temp;
    }

    fraction operator+=(const int num){
        this->numerator+=num*this->denominator;
        fraction temp(this->numerator,this->denominator);
        return temp;
    }

    void setnumerator(int numer){this->numerator=numer;}
    void setdenominator(int denom){this->denominator=denom;}
    int getnumer(){return numerator;}
    int getdenom(){return denominator;}
    void setAll(int numer,int denomer){
        this->setnumerator(numer);
        this->setdenominator(denomer);
    }
    friend std::istream& operator>>(std::istream &in,fraction &ary);
    friend std::ostream& operator <<(std::ostream &,fraction &);
};
void readnumber(fraction *&,char*);
int split_space( char*);
int split_slash(char*);

#endif


