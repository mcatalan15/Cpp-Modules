/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 20:16:01 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/12/13 20:16:02 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

/*
	This tamplate function is used to iterate over an array and apply a function to each
	element of the array. In this case, the function is a print function.
*/
template <typename T>
void	iter(T *array, unsigned int len, void (*print)(T)) {
	if (array) {
		for (unsigned int i = 0; i < len; i++)
			print(array[i]);
	}
}

/*
	This function is used to print the elements of the array.
*/
template <typename T>
void	print(const T elem) {
	std::cout << elem << std::endl;
}

#endif

