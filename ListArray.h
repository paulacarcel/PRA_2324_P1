#ifndef LISTARRAY_H
#define LISTARRAY_H

#include <iostream>
#include "List.h"

template <typename T>
class ListArray : public List<T> {

private:
    T* arr;
    int max;
    int n;
    static const int MINSIZE;

    void resize(int new_size);

public:
    ListArray();
    ~ListArray();

    T operator[](int pos);
    
    template <typename U>
    friend std::ostream& operator<<(std::ostream &out, const ListArray<U> &list);

    void insert(int pos, T e) override;
    void append(T e) override;
    void prepend(T e) override;
    T remove(int pos) override;

    T get(int pos) override;
    int search(T e) override;
    bool empty() override;
    int size() override;
};

// ---------------- IMPLEMENTACIONES ----------------

// Valor mínimo de tamaño
template <typename T>
const int ListArray<T>::MINSIZE = 2;

// Constructor
template <typename T>
ListArray<T>::ListArray() {
    max = MINSIZE;
    n = 0;
    arr = new T[max];
}

// Destructor
template <typename T>
ListArray<T>::~ListArray() {
    delete[] arr;
}

// Método privado resize
template <typename T>
void ListArray<T>::resize(int new_size) {
    if (new_size < MINSIZE)
        new_size = MINSIZE;

    T* new_arr = new T[new_size];

    for (int i = 0; i < n; ++i)
        new_arr[i] = arr[i];

    delete[] arr;
    arr = new_arr;
    max = new_size;
}
template <typename T>
T ListArray<T>::get(int pos) {
    if (pos < 0 || pos >= n) throw std::out_of_range("Posición inválida");
    return arr[pos];
}

template <typename T>
int ListArray<T>::search(T e) {
    for (int i = 0; i < n; ++i)
        if (arr[i] == e) return i;
    return -1;  // No encontrado
}

template <typename T>
bool ListArray<T>::empty() {
    return n == 0;
}

template <typename T>
int ListArray<T>::size() {
    return n;
}
#endif
