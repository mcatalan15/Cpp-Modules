#include "Fixed.hpp"

Fixed::Fixed()	{
	std::cout << "Default constructor called" << std::endl;
	this->num = 0;
}

Fixed::Fixed(Fixed const &src)	{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::~Fixed()	{
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed

