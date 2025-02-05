#include <iostream>
#include <cmath>
#include "Mystack/Mystack.h"
bool is_simple(int n){
    for (int i=2;i<n;i++){
        if (n%i==0){
            return false;
        }
    }
    return true;
}


template<typename Data>
void Multipliers(int value, MyStack<Data> &stack) {
    int value1=abs(value);
    int divider = 2;
    bool correct=true;
    while(correct) {
        if (value1 == 1 or value1==0) {
            std::cout<<"Ошибка"<<"\n";
            correct=false;
        }
        while (value1 > 1) {
            if (value1 % divider == 0 and is_simple(divider)) { ;
                stack.push(divider);
                value1 = value1 / divider;
            } else {
                divider = divider + 1;
            }
        }
        correct=false;
    }

}

int main(int argc, char* argv[]){

    MyStack<int> Multi;
    int multi;
    std::cin>>multi;
    Multipliers(multi,Multi);
    if(multi<0){
        std::cout<<multi<<" = -(";
        Multi.print();
        std::cout<<")";
        std::cout<<"\n";
        std::cout<<multi<<" = -(";
        Multi.printback();
        std::cout<<")";

    }
    else{
        std::cout<<multi<<" = ";
        Multi.print();
        std::cout<<"\n";
        std::cout<<multi<<" = ";
        Multi.printback();

    }


}

