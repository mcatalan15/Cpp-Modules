/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 11:14:25 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/09/05 19:11:18 by mcatalan@st      ###   ########.fr       */
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

int	Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (num);
}

void	Fixed::setRawBits(int const raw) {
	this->num = raw;
}

