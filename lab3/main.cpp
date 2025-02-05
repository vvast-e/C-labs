#include "fraction/fraction.h"
#define count 1

int main(int argc, char* argv[]) {
    system("chcp 65001>nul");
    // ввод дроби с клавиатуры
    std::cout << "Введите дробь: \n";
    fraction z;
    std::cin >> z;
    std::cout << "z=" << z;
    // проверка конструкторов
    fraction fr1(10, 14), fr2;
    std::cout << "fr2=" << fr2;
    std::cout << "fr1=" << fr1;
    fraction fr = "-1 4/8";
    std::cout << "fr=" << fr;
    fraction x(z), y;
    std::cout << "x=" << x;
    double dbl = -1.25;
    fraction f = dbl;
    std::cout << "f=" << f;
    // проверка перегруженной операции "+"
    y = x + z;
    std::cout << "y=" << y;
    y += x;
    f += dbl / 2;
    std::cout << "f=" << f;
    y = x + dbl;
    std::cout << "y=" << y;
    y = dbl+y;
    std::cout << "y=" << y;
    y += dbl;
    std::cout << "y=" << y;
    int i = 5;
    y += i;
    std::cout << "y=" << y;
    y = i + x;
    std::cout << "y=" << y;
    y = x + i;
    std::cout << "y=" << y;
    y+=dbl+i+x;
    std::cout<<"y="<<y;

}


