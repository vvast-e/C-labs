

#ifndef LAB5_VECTOR_H
#define LAB5_VECTOR_H
#include <iostream>
#include <cstring>

const int MAX_SIZE = 5;

template<typename INF>
class MyVector {
protected:
    int max_size;
    int size;
    INF *pdata;
    void resize();

public:
    // Конструктор вектора при создании
    MyVector(INF el, int max_size = MAX_SIZE) {
        this->size = 0;
        this->max_size = max_size;
        this->pdata = new INF[max_size];
        if (el) {
            add_element(el);
        }
    }
    MyVector(){
        this->size=0;
        this->max_size=MAX_SIZE;
        this->pdata=new INF[max_size];
    }

    // Конструктор копирования вектора
    MyVector(MyVector &v);

    // Деструктор вектора
    ~MyVector();

    virtual // Функция добавления элемента в вектор
    void add_element(INF el);

    // Функция удаления элемента из вектора
    bool delete_element(int i);

    // Перегрузка оператора обращения по индексу
    INF operator[](int i);

    void sort() {
        for (size_t i = 0; i < size; i++) {
            for (size_t j = 0; j < size - 1; j++) {
                if (pdata[j] > pdata[j + 1]) {
                    std::swap(pdata[j], pdata[j + 1]);
                }
            }
        }
    }

    // Функция получения текущего размера вектора
    int get_size() { return size; }

    // Функция получения максимального размера вектора
    int get_max_size() { return max_size; }

    // Поиск элемента
    int find(INF el);

    // Перегрузка равно (=)
    MyVector &operator=(MyVector &v) {
        if (this != &v) {
            delete[] pdata;
            this->size = v.size;
            this->max_size = v.max_size;
            this->pdata = new INF[this->max_size];
            for (size_t i = 0; i < this->size; i++) {
                this->pdata[i] = v.pdata[i];
            }
        }
        return *this;
    }

    // Френдовая функция перегрузки вывода
    friend std::ostream &operator<<(std::ostream &out, MyVector<INF> &v) {
        std::cout << "[";
        for (int i = 0; i < v.size; ++i) {
            if (i == 0) {
                std::cout << v.pdata[i];
            } else {
                std::cout << ", " << v.pdata[i];
            }
        }
        std::cout << "]";
        return out;
    }
};

template<typename INF>
bool MyVector<INF>::delete_element(int i) {
    if (i < 0 || i >= size) {
        return false;
    } else {
        for (int j = i; j < size; ++j) {
            pdata[j] = pdata[j + 1];
        }
        size--;
        resize();
        return true;
    }
}

template<typename INF>
int MyVector<INF>::find(INF el) {
    for (int i = 0; i < size; ++i) {
        if (pdata[i] == el) {
            return i;
        }
    }
    return -1;
}

template<typename INF>
INF MyVector<INF>::operator[](int i) {
    return pdata[i];
}

template<typename INF>
void MyVector<INF>::add_element(INF el) {
    size++;
    resize();
    pdata[size - 1] = el;
}

template<typename INF>
MyVector<INF>::~MyVector() {
    delete[] pdata;
}

template<typename INF>
MyVector<INF>::MyVector(MyVector &v) {
    this->size = v.size;
    this->max_size = v.max_size;
    this->pdata = new INF[max_size];
    for (int i = 0; i < size; ++i) {
        pdata[i] = v.pdata[i];
    }
}

template<typename INF>
void MyVector<INF>::resize() {
    if (size > max_size) {
        max_size *= 2;
    } else if (size < max_size / 4) {
        (max_size / 2 > MAX_SIZE) ? max_size /= 2 : max_size = MAX_SIZE;
    }
    INF *newpdata = new INF[max_size];
    for(int i=0;i<size;i++){
        newpdata[i]=pdata[i];
    }
    delete[] pdata;
    pdata=newpdata;
}

template<>
void MyVector<char *>::add_element(char *el) {
    size++;
    resize();
    this->pdata[this->size-1] = new char[strlen(el) + 1];
    strcpy(this->pdata[this->size-1], el);
}

template<>
MyVector<char *>::MyVector(char *el, int max_size) {
    this->size = 0;
    this->max_size = max_size;
    this->pdata = new char *[max_size];
    if (el) {
        add_element(el);
    }
}

template<>
MyVector<char *>::MyVector(MyVector &v) {
    this->max_size = v.max_size;
    this->size = v.size;
    this->pdata = new char *[this->max_size];
    for (size_t i = 0; i < this->size; i++) {
        this->pdata[i] = new char[strlen(v.pdata[i]) + 1];
        strcpy(this->pdata[i], v.pdata[i]);
    }
}

template<>
MyVector<char *>::~MyVector() {
    for(int i=0;i<this->size;i++){
        delete [] this->pdata[i];
    }
    delete[] this->pdata;
}

template<>
bool MyVector<char *>::delete_element(int index) {
    if (index >= this->size || index < 0) {
        return false;
    }
    delete[] this->pdata[index];
    for (size_t i = index; i < this->size - 1; i++) {
        this->pdata[i] = this->pdata[i + 1];
    }
    this->size--;
    resize();
    return true;
}

template<>
int MyVector<char *>::find(char *el) {
    for (size_t i = 0; i < this->size; i++) {
        if (!strcmp(el, pdata[i])) {
            return static_cast<int>(i);
        }
    }
    return -1;
}

template<>
MyVector<char *> &MyVector<char *>::operator=(MyVector &v) {
    if (this != &v) {
        for(int i=0;i<this->size;i++){
            delete [] pdata[i];
        }
        delete[] pdata;
        this->size = v.size;
        this->max_size = v.max_size;
        this->pdata = new char *[this->max_size];
        for (size_t i = 0; i < this->size; i++) {
            this->pdata[i]=new char[strlen(v.pdata[i])+1];
            strcpy(pdata[i],v.pdata[i]);
        }
    }
    return *this;
}
#endif //LAB5_VECTOR_H
