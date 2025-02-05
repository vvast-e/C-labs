#ifndef Aparts_LIBRARY_H
#define Aparts_LIBRARY_H

#include <cstring>
#include <iostream>
#include <fstream>
#include <iomanip>

class Aparts {
public:
    Aparts(char *name = "\0", int square = 0, int price = 0, int metro = 0) {
        _name = new char[strlen(name) + 1];
        strcpy(_name, name);
        _square = square;
        _price=price;
        _metro=metro;

    }

    ~Aparts() {
        delete[] _name;
    }

    void setName(char *Name1) {
        delete[] _name;
        _name = new char[strlen(Name1) + 1];
        strcpy(_name, Name1);
    }

    void setsquare(int square) { this->_square = square; }

    void setmetro(bool metro) { this->_metro = metro; }

    void setprice(int price) { this->_price = price; }

    void setAll(char *name, int square, bool metro, int price) {
        this->setName(name);
        this->setsquare(square);
        this->setmetro(metro);
        this->setprice(price);
    }

    char *getName() { return _name; }

    int getsquare() { return _square; }

    bool getmetro() { return _metro; }

    int getprice() { return _price; }

private:
    char *_name;
    int _square;
    bool _metro;
    int _price;
};

int readfile(const char *Filename, Aparts *&ary);

void print_base(int, Aparts *);

void write_in_file(int, Aparts *);

int find_ind(Aparts *, int, const char *);

Aparts *delete_aparts(Aparts *, int &);

Aparts *add_aparts(Aparts *, int &);

Aparts *edit_aparts(Aparts *, int);

void swap(Aparts *, int, int);

Aparts *sort_square(Aparts *, int);

#endif //Aparts_LIBRARY_H
