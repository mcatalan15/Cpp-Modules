/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 20:53:03 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/09/05 19:57:32 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/*
	This project is about the Ortodox Canonical Form (OCF). In this case, we will
	apply the OCF to the Fixed class. The Fixed class will have a num member and
	a bits member. The num member will be initialized to 0 and the bits member
	will be initialized to 0.

	- Create three Fixed objects.
	- Create a Fixed object a.
	- Create a Fixed object b and initialize it with a.
	- Create a Fixed object c and assign b to it.
	- Print the raw value of a, b and c.

	Expected output:
	1.Fixed a: "Default constructor called" + num of a is initialized to 0.
	2.Fixed b(a): "Copy constructor called" + num of b will have the num member as a.num(0).
	3.Fixed c: "Default constructor called" + num of c is initialized to 0.
	4.c = b: "Copy assignment operator called" + c.num is assigned the value of b.num(0).
	5.std getRawBits(): "getRawBits member function called" + prints the raw value of a, b and c.
*/

int	main()	{

	Fixed a;
	Fixed b(a);
	Fixed c;
	c = b;

	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;

	return 0;
}

