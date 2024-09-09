/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 11:14:25 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/09/09 18:04:16 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//Constructor with output and initialization of fPointValue.

Fixed::Fixed()	{
	std::cout << "Default constructor called" << std::endl;
	this->fPointValue = 0;
}

/*
	Copy constructor with output and initialize the object using an existing object.
*/

Fixed::Fixed(Fixed const &src)	{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

/*
	Int constructor. Init fPointValue with the value of numI shifted left by fBits.
*/
Fixed::Fixed(int const numI) {
	std::cout << "Integer constructor called" << std::endl;
	this->fPointValue = numI << fBits;
}

/*
	Float constructor. Init fPointValue with the value of numF multiplied by 2 raised to the power of fBits.
	- roundf() rounds the float to the nearest integer value.
	- (1 << this->fBits) is equivalent to 2 raised to the power of fBits.
*/
Fixed::Fixed(float const numF) {
	std::cout << "Float constructor called" << std::endl;
	this->fPointValue = roundf(numF * (1 << this->fBits));
}

//Destructor with output.

Fixed::~Fixed()	{
	std::cout << "Destructor called" << std::endl;
}

/*
	Copy assignment operator with output.
	If the object is not the same as the one passed as an argument, the value of the private
	member fPointValue is assigned the value of the object passed as an argument with getRawBits().
	Returns a reference to the object
*/

Fixed &Fixed::operator=(Fixed const &raw) {
	std::cout << "Copy assigment operator called" << std::endl;
	if (this != &raw) {
		this->fPointValue = raw.getRawBits();
	}
	return (*this);
}

/*
	Converting the fixed point value to an integer.
	-Divide the value of fPointValue by 2 raised to the power of fBits.
*/

int	Fixed::toInt(void) const { return (this->fPointValue >> this->fBits);}

/*
	Converting the fixed point value to a float.
	-Divide the value of fPointValue by 2 raised to the power of fBits.
	same as toInt() but returns a float.
*/

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
/*
	Overload of the operator "<<" to output the value of the object as a float.
	Const version to handle const and non const objects.
*/
std::ostream &operator<<(std::ostream &out, Fixed const &rhs)
{
	out << rhs.toFloat();
	return (out);
}

// operador "<<"
/*
	Overload of the operator "<<" to output the value of the object as a float.
	Same as the const version but for non const objects.
*/
std::ostream &operator<<(std::ostream &out, Fixed &rhs)
{
	out << rhs.toFloat();
	return (out);
}
