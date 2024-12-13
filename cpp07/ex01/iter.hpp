#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

/*
	This tamplate function is used to iterate over an array and apply a function to each
	element of the array. In this case, the function is a print function.
*/
template <typename T>
void	iter(T *array, unsigned int len, void (*f)(T)) {
    if (array) {
        for (unsigned int i = 0; i < len; i++)
            f(array[i]);
    }
}

/*
	This function is used to print the elements of the array.
*/
template <typename T>
void    print(const T elem) {
    std::cout << elem << std::endl;
}

#endif

