/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 20:16:12 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/12/13 20:16:13 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

/*
	Default constructor: Initializes the pointer to NULL and the size to 0.
*/
template <class T>
Array<T>::Array() {
    this->_arr = NULL;
    this->_n = 0;
}

/*
	Constructor: Initializes the array with 'n' elements and the size to 'n'.
*/
template <class T>
Array<T>::Array(unsigned int n) {
    this->_arr = new T[n];
    this->_n = n;
}

/*
	Copy constructor: Creates a depp copy of another Array object.
	Cheks if the size of the array is different from 0 (the array is empty),
	if it is, it creates a new array and copies the elements of the source array.
*/
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

/*
	Destructor: Deallocates the memory of the array.
*/
template <class T>
Array<T>::~Array() {
    if (this->_n != 0)
        delete [] _arr;
}

/*
	Assigment operator: assigns the content of the array to another array.
	Checks if the size of the array is different from 0 (the array is empty),
	if it is, it creates a new array and copies the elements of the source array.
*/
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

/*
	Operator[]: is used to access the elements of the array.
	Checks if the index is less than the size of the array, if it is, it returns the element of
	the array. Otherwise, it throws an exception.
*/
template <class T>
T &Array<T>::operator[](unsigned int n) {
    if (n < this->_n) {
        return (this->_arr[n]);
    } else {
        throw std::exception();
    }
}

/*
	Size: is used to return the size of the array.
*/
template <class T>
unsigned int Array<T>::size() const {
    return (this->_n);
}

