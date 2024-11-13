#include "Array.hpp"

template <class T>
Array<T>::Array() {
    this->_arr = NULL;
    this->_n = 0;
}

template <class T>
Array<T>::Array(unsigned int n) {
    this->_arr = new T[n];
    this->_n = n;
}

template <class T>
Array<T>::Array(const Array<T> &src) {
    this->_n = src._n;
    if (src._n != 0) {
        this->_arr = new T[src._n];
        for(unsigned int i = 0; i < src._n; i++) {
            this->_arr[i] = src._arr[i];
        }
    } else {
        this->_arr = NULL;
    }
}

template <class T>
Array<T>::~Array() {
    if (this->_n != 0)
        delete [] _arr;
}

//Operator "="
template <class T>
Array<T> &Array<T>::operator=(const Array<T> &src) {
    if (this->_n != 0) {
        delete [] _arr;
        this->_arr = NULL;
    }
    this->_n = src._n;
    if (src._n != 0) {
        this->_arr = new T[src._n];
        for (unsigned int i = 0; i < src._n; i++) {
            this->_arr[i] = src._arr[i];
        }
    } else {
        this->_arr = NULL;
    }
    return (*this);
}

template <class T>
T &Array<T>::operator[](unsigned int n) {
    if (n < this->_n) {
        return (this->_arr[n]);
    } else {
        throw std::exception();
    }
}

// Functions
template <class T>
unsigned int Array<T>::size() const {
    return (this->_n);
}

