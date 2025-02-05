//
// Created by User on 20.04.2024.
//

#ifndef LAB6_VECTOR_H
#define LAB6_VECTOR_H

#include <iostream>
#include <algorithm>
const int MAX_SIZE= 1;
template<typename INF>
class vector{
protected:
    int max_size;
    int size;
    INF *pdata;
public:
    vector(){
        max_size=MAX_SIZE;
        pdata=new INF[max_size];
        size=0;
    };
    vector(int maxsize,int _size,INF *data){
        max_size=maxsize;
        size=_size;
        pdata=data;
    }
    vector(int maxsize,int _size){
        max_size=maxsize;
        pdata=new INF[max_size];
        size=_size;
    }
    vector(vector &vec){
        this->pdata=vec.pdata;
        this->size=vec.size;
        this->max_size=vec.max_size;
    };
    ~vector(){};
    int getsize() const {return this->size;}
    virtual void add_element(INF elem);
    void delete_element(int index);
    int find_elem(INF elem);
    void resizeup();
    void resizedown();
    void print();
    void sort();
    vector reverse(){
        vector temp(max_size,size);
        for(int i=0,j=size-i-1;i<size;++i,--j){
            temp.pdata[i]=pdata[j];
        }
        *this=temp;
        return *this;
    };
    void clear(){
        max_size=1;
        size=0;
        delete[] pdata;
    }
    vector<INF> &operator=(const vector &vec){
        this->pdata=vec.pdata;
        this->size=vec.size;
        this->max_size=vec.max_size;
        return *this;
    };
    INF operator[](int index);


};



template<typename INF>
INF vector<INF>::operator[](int index) {
    return pdata[index];
}


template<typename INF>
void vector<INF>::resizeup() {
    if(size==max_size){
        max_size*=2;
    }
}


template<typename INF>
void vector<INF>::add_element(INF elem) {
    resizeup();
    INF *temp=new INF[max_size];
    for(int i=0;i<max_size;i++){
        temp[i]=pdata[i];
    }
    delete[] pdata;
    pdata=temp;
    pdata[size]=elem;
    size++;

}

template<typename INF>
void vector<INF>::resizedown() {
    if(size<max_size/4){
        max_size/=2;
    }
}

template<typename INF>
void vector<INF>::delete_element(int index) {
    INF *temp=new INF[max_size-1];
    int j=0;
    for(int i=0;i<index;i++){
        temp[j++]=pdata[i];
    }
    for(int i=index+1;i<max_size;i++){
        temp[j++]=pdata[i];
    }
    delete[] pdata;
    pdata=temp;
    size--;
    resizedown();
}

template<typename INF>
int vector<INF>::find_elem(INF elem) {
    for(int i=0;i<max_size;i++){
        if(pdata[i]==elem){
            return i;
        }
    }
    return -1;
}
template<typename INF>
void vector<INF>:: print()
{
    for (int i = 0; i <size ; i++) {
        std::cout << pdata[i] << " ";
    }
    std::cout << "\n";
}

template<typename INF>
void vector<INF>::sort() {
    for(int i=0;i<this->size;i++){
        for(int j=1;j<this->size-i;j++){
            if(this->pdata[j-1]>this->pdata[j]){
                INF temp=this->pdata[j-1];
                this->pdata[j-1]=this->pdata[j];
                this->pdata[j]=temp;
            }
        }
    }
}
#endif //LAB6_VECTOR_H
