/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 20:16:08 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/12/13 20:16:09 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#define CYAN "\033[36m"
#define RESET "\033[0m"
#define RED "\033[31m"

/*
	This class is used to create an array of any type. 
	Private:
		_arr: is a pointer to the array.
		_n: is the size of the array.
	public:
		Ortodox canonical form.
		operator[]: is used to access the elements of the array.
		size: is used to return the size of the array.
*/
template <class T>
class	Array {
	private:
		T*				_arr;
		unsigned int	_n;

	public:
		Array();
		Array(unsigned int n);
		Array(const Array &src);
		Array &operator=(const Array &src);
		~Array();

		T &operator[](unsigned int n);
		unsigned int	size() const;
};

#endif
