#ifndef PLANETS_LIBRARY_H
#define PLANETS_LIBRARY_H

#include <cstring>
#include <iostream>
#include <fstream>

class Planets {
public:
    Planets() {
        _name = new char[20];
        _diameter = _satellites = _life = 0;
    }

    ~Planets() {
        delete[] _name;
    }

    void setName(char *Name1) {
        _name = new char[strlen(Name1) + 1];
        strcpy(_name, Name1);
    }

    void setDiam(int diameter) { this->_diameter = diameter; }

    void setLife(bool life) { this->_life = life; }

    void setSatellites(int satellites) { this->_satellites = satellites; }

    void setAll(char *name, int diameter, bool life, int satellites) {
        this->setName(name);
        this->setDiam(diameter);
        this->setLife(life);
        this->setSatellites(satellites);
    }

    char *getName() { return _name; }

    int getDiam() { return _diameter; }

    bool getLife() { return _life; }

    int getSatellites() { return _satellites; }

private:
    char *_name;
    int _diameter;
    bool _life;
    int _satellites;
};
std::ostream& operator << (std::ostream &os, Planets &Planets);

std::istream& operator>>(std::istream &in,Planets &Planets);

Planets* readfile(const char *Filename, int &count);

void print_base(int, Planets*);

void write_in_file(int,Planets*);

int find_ind(Planets*,int, const char*);

Planets *delete_planet(Planets*,int&);

Planets *add_planet(Planets*, int&);

Planets *edit_planet(Planets*,int);

void swap(Planets*,int,int);

Planets *sort_diam(Planets*,int,bool);

#endif //PLANETS_LIBRARY_H
