/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 11:14:25 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/09/07 12:53:00 by mcatalan@st      ###   ########.fr       */
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
	Int constructor. Init fPointValue with the value of numI shifted left by fBits.
*/
Fixed::Fixed(int const numI) { this->fPointValue = numI << fBits; }

/*
	Float constructor. Init fPointValue with the value of numF multiplied by 2 raised to the power of fBits.
*/
Fixed::Fixed(float const numF) { this->fPointValue = roundf(numF * (1 << this->fBits)); }

//Destructor with output.

Fixed::~Fixed()	{}

/*
	Copy assignment operator.
*/

// operator "="
Fixed &Fixed::operator=(Fixed const &raw) {
	if (this != &raw) {
		this->fPointValue = raw.getRawBits();
	}
	return (*this);
}

/*
	*COMPARATORS OPERATORS
	Allowing to compare two objects from the same class.
	Compares if the current object(fPointValue) is greater than the object passed as an
	argument(raw.fPointValue).
	Using the ternary operator in case the condition is true, it returns true, otherwise false.
*/
//  operator ">"
bool	Fixed::operator>(Fixed const &raw) const {
	return (this->fPointValue > raw.fPointValue ? true : false);
}
// operator "<"
bool	Fixed::operator<(Fixed const &raw) const {
	return (this->fPointValue < raw.fPointValue ? true : false);
}
// operator ">="
bool	Fixed::operator>=(Fixed const &raw) const {
	return (this->fPointValue >= raw.fPointValue ? true : false);
}
// operator "<="
bool	Fixed::operator<=(Fixed const &raw) const {
	return (this->fPointValue <= raw.fPointValue ? true : false);
}
// operator "=="
bool	Fixed::operator==(Fixed const &raw) const {
	return (this->fPointValue == raw.fPointValue ? true : false);
}
// operator "!="
bool	Fixed::operator!=(Fixed const &raw) const {
	return (this->fPointValue != raw.fPointValue ? true : false);
}
/*
	*Aritmetic operators
	Allowing to perform arithmetic operations on two objects of the same class.
	Converts the fixed point value to a float and performs the operation.
*/
// operator "+"
float	Fixed::operator+(Fixed const &raw) const {
	return (this->toFloat() + raw.toFloat());
}
// operator "-"
float	Fixed::operator-(Fixed const &raw) const {
	return (this->toFloat() - raw.toFloat());
}
// operator "*"
float	Fixed::operator*(Fixed const &raw) const {
	return (this->toFloat() * raw.toFloat());
}
// operator "/"
float	Fixed::operator/(Fixed const &raw) const {
	return (this->toFloat() / raw.toFloat());
}

/*
	*INCREMENT AND DECREMENT OPERATORS
	Allowing to increment and decrement the value of the object.
	Gets the value of fPointValue and adds or removes 1 to it.
	-PREOPERATORS
		Adds or removes 1 to the value of fPointValue.
	-POSTOPERATORS
		Adds or removes 1 to the value of fPointValue and returns
		the value before the operation saved in a temporary object (init).
*/
// operator "++"
Fixed Fixed::operator++(void) {
	this->fPointValue = this->fPointValue + 1;
	return (*this);
}
// operator "--"
Fixed Fixed::operator--(void) {
	this->fPointValue = this->fPointValue - 1;
	return (*this);
}
// operator "++"
Fixed Fixed::operator++(int) {
	Fixed init(*this);
	this->fPointValue = this->fPointValue + 1;
	return (init);
}
// operator "--"
Fixed Fixed::operator--(int) {
	Fixed init(*this);
	this->fPointValue = this->fPointValue - 1;
	return (init);
}
/*
	MAX MIN OPERATORS
	Allowing to compare two objects of the same class and return the greater or smaller one.
	Use the ternary operator to compare the two objects. If the condition is true, it returns
	the first object, otherwise the second.
	min and max has to functions, one for const objects and another for non-const objects.
*/
// operator "min"
const	Fixed &Fixed::min(Fixed const &first, Fixed const &second) {
	return (first < second ? first : second);
}

Fixed &Fixed::min(Fixed &first, Fixed &second) {
	return (first < second ? first : second);
}
// operator "max"
const	Fixed &Fixed::max(Fixed const &first, Fixed const &second) {
	return (first > second ? first : second);
}

Fixed &Fixed::max(Fixed &first, Fixed &second) {
	return (first > second ? first : second);
}

/*
	Converting the fixed point value to an integer or float.
*/

int	Fixed::toInt(void) const { return (this->fPointValue >> this->fBits);}

float Fixed::toFloat(void) const { return ((float)this->fPointValue / (1 << this->fBits)); }

/*
	A getter function. Returns the value of the private member fPointValue.
*/

int	Fixed::getRawBits(void) const {
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
