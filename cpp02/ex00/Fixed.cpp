/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 11:14:25 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/09/05 20:19:08 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//Constructor with output and initialization of num.

Fixed::Fixed()	{
	std::cout << "Default constructor called" << std::endl;
	this->num = 0;
}

/*
	Copy constructor with output and initialize the object using another object.
*/

Fixed::Fixed(Fixed const &src)	{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

//Destructor with output.

Fixed::~Fixed()	{
	std::cout << "Destructor called" << std::endl;
}

/*
	Why a copy assignment operator?
	In C++, the copy assignment operator is used to copy the data from one object to another.
	When we assign one object to another, the copy assignment operator is called.

	To allow the copy assignment operator to work, we need to overload the assignment operator.
	We can do this by defining a member function with the name operator= and the following syntax:
	- ReturnType operator=(const ClassName &rhs);

	The copy assignment operator. Used when an object is assigned the value of
	another object.
	- Print a message.
	- Check if the object is not the same as the one being assigned. (this != &raw)
	- Sets the num member to the value of raw's (the object) num.
	- Returns a reference to the object.
*/

Fixed &Fixed::operator=(Fixed const &raw) {
	std::cout << "Copy assigment operator called" << std::endl;
	if (this != &raw) {
		this->num = raw.getRawBits();
	}
	return (*this);
}

/*
	A getter function. Returns the value of the private member num.
*/

int	Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (num);
}

/*
	A setter function. Sets the value of the private member num.
*/

void	Fixed::setRawBits(int const raw) { this->num = raw; }

