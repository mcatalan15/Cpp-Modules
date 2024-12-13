#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

/*
	This tamplete functions is used to swap the values of two variables.
*/
template <typename T>
void swap(T& a, T& b) {
    T tmp;

    tmp = a;
    a = b;
    b = tmp;
}

/*
	This tamplete functions is used to return the minimum value between two values.
*/
template <typename T>
const T min(const T& a, const T& b) {
    return (a < b ? a : b);
}

/*
	This tamplete functions is used to return the maximum value between two values.
*/
template <typename T>
const T max(const T& a, const T& b) {
    return (a > b ? a : b);
}

#endif // WHATEVER_HPP

