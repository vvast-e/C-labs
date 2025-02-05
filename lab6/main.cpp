#include <iostream>
#include <limits>
#include "polynomial/polynomial.h"
#include <vector>
#include <cstdlib>
int main() {

    Polynomial z;
    if (!(std::cin >> z)) {
        std::cerr << "Ошибка при вводе первого многочлена." << std::endl;
        std::cin.clear();
        std::cin.sync();
        return 1;
    }

    Polynomial a;
    if (!(std::cin >> a)) {
        std::cerr << "Ошибка при вводе первого многочлена." << std::endl;
        std::cin.clear();
        std::cin.sync();
        return 1;
    }
    std::cout<<z;
    std::cout<<a;
    a*=z;
    std::cout<<a;
    a+=z;
    std::cout<<a;
/*    z+=a;
    std::cout<<z;*/
}