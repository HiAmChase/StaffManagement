#pragma once
#include <iostream>
using namespace std;

template<class T>
class List {
private:
    T* data;
    int length;
    int count;
public:
    List();
    List(int);
    ~List();
    void insert(const T&);
    int size();
    void clear();
    int indexOf(const T&);
    void removeAt(int);
    T& operator[](int);
};