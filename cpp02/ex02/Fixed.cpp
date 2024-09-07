/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 11:14:25 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/09/06 16:41:54 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//Constructor with output and initialization of fPointValue.

Fixed::Fixed()	{ this->fPointValue = 0; }

/*
	Copy constructor with output and initialize the object using another object.
*/

Fixed::Fixed(Fixed const &src)	{ *this = src; }

/*
	Int constructor
*/
Fixed::Fixed(int const numI) { this->fPointValue = numI << fBits; }

/*

*/
Fixed::Fixed(float const numF) { this->fPointValue = roundf(numF * (1 << this->fBits)); }

//Destructor with output.

Fixed::~Fixed()	{}

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

//COMPARATORS OPERATORS
// operator "="

Fixed &Fixed::operator=(Fixed const &raw) {
	std::cout << "Copy assigment operator called" << std::endl;
	if (this != &raw) {
		this->fPointValue = raw.getRawBits();
	}
	return (*this);
}

// operator ">"
// operator "<"
// operator ">="
// operator "<="
// operator "=="
// operator "!="
// operator "+"
// operator "-"
// operator "*"
// operator "/"

//INCREMENT AND DECREMENT OPERATORS
//PREOPERATORS
// operator "++"
// operator "--"

//POSTOPERATORS
// operator "++"
// operator "--"

//MAX MIN OPERATORS
// operator "min"
// operator "max"


int	Fixed::toInt(void) const { return (this->fPointValue >> this->fBits);}

float Fixed::toFloat(void) const { return ((float)this->fPointValue / (1 << this->fBits)); }

/*
	A getter function. Returns the value of the private member fPointValue.
*/

int	Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (fPointValue);
}

/*
	A setter function. Sets the value of the private member fPointValue.
*/

void	Fixed::setRawBits(int const raw) { this->fPointValue = raw; }

// operador "<<" (const)
std::ostream &operator<<(std::ostream &out, Fixed const &rhs)
{
	out << rhs.toFloat();
	return (out);
}

// operador "<<"
std::ostream &operator<<(std::ostream &out, Fixed &rhs)
{
	out << rhs.toFloat();
	return (out);
}
