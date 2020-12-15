#include "List.h"

template<class T>
List<T>::List()
    : data(nullptr), length(0), count(0) {}

template<class T>
List<T>::List(int length) {
    this->length = length;
    this->count = 0;
    this->data = new T[this->length];
}

template<class T>
List<T>::~List() {
    delete[] this->data;
}

template<class T>
void List<T>::insert(const T& item) {
    // trường hợp đầy bộ nhớ
    if (this->length == 0) {
        this->length = 1;
        this->count = 1;
        this->data = new T[this->length];
        this->data[0] = item;
        return;
    }
    if (this->count == this->length) {
        T* temp = new T[this->length];

        for (int i = 0; i < this->length; i++) {
            temp[i] = this->data[i];
        }

        delete[] this->data;

        this->data = new T[this->length * 2];

        for (int i = 0; i < this->length; i++) {
            *(this->data + i) = *(temp + i);
        }

        this->data[this->count] = item;
        this->length *= 2;
    }
    else {
        *(this->data + this->count) = item;
    }
    this->count += 1;
}

template<class T>
int List<T>::size() {
    return this->count;
}

template<class T>
void List<T>::clear() {
    delete[] this->data;
    this->data = nullptr;
    this->count = 0;
    this->length = 0;
}

template<class T>
int List<T>::indexOf(const T& item) {
    for (int i = 0; i < this->count; i++) {
        if (*(this->data + i) == item)
            return i;
    }
    return -1;
}

template<class T>
void List<T>::removeAt(int index) {
    if (index < 0 && index >= this->count)
        return;
    if (this->count == 1) {
        clear();
        return;
    }
    T* temp = new T[this->length];
    for (int i = 0; i < this->length; i++) {
        temp[i] = this->data[i];
    }

    delete[] this->data;

    this->data = new T[this->length];
    for (int i = 0; i < index; i++) {
        *(this->data + i) = *(temp + i);
    }
    for (int i = index + 1; i < this->length; i++) {
        *(this->data + i - 1) = *(temp + i);
    }
    this->count -= 1;
}

template<class T>
T& List<T>::operator[](int index) {
    //if (index >= 0 && index < this->count)
    return *(this->data + index);
    //throw exception
}
