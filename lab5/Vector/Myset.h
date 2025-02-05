//
// Created by User on 13.05.2024.
//

#ifndef LAB5_MYSET_H
#define LAB5_MYSET_H
#include <iostream>

#include "Vector.h"

template<typename INF>
class MySet : public MyVector<INF> {
public:
    MySet() : MyVector<INF>() {};
    MySet(INF el) : MyVector<INF>(el) {};
    bool operator==(MySet &s) {
        if (this->size != s.size || this->max_size != s.max_size) {
            return false;
        }

        for (size_t i = 0; i < this->size; i++) {
            if (this->pdata[i] != s.pdata[i]) {
                return false;
            }
        }

        return true;
    }

    MySet &operator+=(MySet &s) {
        for (size_t i = 0; i < s.size; i++) {
            this->add_element(s.pdata[i]);
        }
        return *this;
    }

    MySet &operator-=(MySet &s) {
        for (size_t i = 0; i < s.size; i++) {
            this->delete_element(s.pdata[i]);
        }

        return *this;
    }

    MySet &operator*=(MySet &s) {
        for (size_t i1 = 0, i2 = 0; i1 < this->size && i2 < s.size;) {
            if (this->pdata[i1] != s.pdata[i2]) {
                if (this->pdata[i1] < s.pdata[i2]) {
                    i1++;
                } else {
                    i2++;
                }
            } else {
                this->add_element(this->pdata[i1]);
                i1++, i2++;
            }
        }
        return *this;
    }

    MySet &operator=(const MySet &s) {
        if (this != &s) {
            this->size = s.size;
            this->max_size = s.max_size;

            this->pdata = new INF[this->max_size];

            for (size_t i = 0; i < this->size; i++) {
                this->pdata[i] = s.pdata[i];
            }
        }

        return *this;
    }

    void add_element(INF el) {
        if (is_element(el)) {
            return;
        }

        MyVector<INF>::add_element(el);
        this->sort();
    }

    void delete_element(INF el) {
        if (!is_element(el)) {
            return;
        }
        int i = q_find(el);

        if (i >= this->size) {
            return;
        }

        MyVector<INF>::delete_element(i);
    }

    int q_find(INF el) {
        int l = 0, r = this->size;
        while (r - l > 1) {
            int m = (l + r) / 2;
            if (this->pdata[m] > el) {
                r = m;
            } else {
                l = m;
            }
        }

        return l;
    }

    bool is_element(INF el) {
        int i = q_find(el);

        if (i >= this->size) {
            return false;
        }

        return this->pdata[i] == el;
    }

    friend MySet operator+(MySet &s1, MySet &s2) {
        MySet set(s1);
        for (size_t i = 0; i < s2.size; i++) {
            set.add_element(s2.pdata[i]);
        }
        return set;
    }

    friend MySet operator-(MySet &s1, MySet &s2) {
        MySet set(s1);
        for (size_t i = 0; i < s2.size; i++) {
            set.delete_element(s2.pdata[i]);
        }

        return set;
    }

    friend MySet operator*(MySet& s1,MySet &s2) {
        MySet set;
        for(int i=0;i<s1.size;i++){
            if(s2.is_element(s1.pdata[i])){
                set.add_element(s1.pdata[i]);
            }
        }
        return set;
    }
};

template<>
bool MySet<char *>::operator==(MySet &s) {
    if (this->size != s.size || this->max_size != s.max_size) {
        return false;
    }

    for (size_t i = 0; i < this->size; i++) {
        if (strcmp(this->pdata[i], s.pdata[i]) != 0) {
            return false;
        }
    }

    return true;
}

template<>
int MySet<char *>::q_find(char *el) {
    int l = 0, r = this->size;
    while (r - l > 1) {
        int m = (l + r) / 2;
        if (strcmp(this->pdata[m], el) == 1) {
            r = m;
        } else {
            l = m;
        }
    }

    return l;
}

template<>
bool MySet<char *>::is_element(char *el) {
    int i = q_find(el);

    if (i >= this->size) {
        return false;
    }

    return !strcmp(this->pdata[i], el);
}



template<>
MySet<char *> &MySet<char *>::operator=(const MySet &s) {
    if (this != &s) {
        for(int i=0;i<size;i++){
            delete [] pdata[i];
        }
        delete[] pdata;
        this->size = s.size;
        this->max_size = s.max_size;

        this->pdata = new char *[this->max_size];

        for (size_t i = 0; i < this->size; i++) {
            this->pdata[i] = new char[strlen(s.pdata[i]) + 1];
            strcpy(this->pdata[i], s.pdata[i]);
        }
    }

    return *this;
}



#endif //LAB5_MYSET_H
