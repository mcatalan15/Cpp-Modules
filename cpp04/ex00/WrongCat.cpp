/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 18:14:29 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/09/20 17:11:37 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("cat")
{
	this->_type = "cat";
	std::cout << "WrongCat default constructor called." << std::endl;
}

WrongCat::WrongCat(const WrongCat &src) : WrongAnimal(src)
{
	*this = src;
	std::cout << "WrongCat copy constructor called." << std::endl;
}

WrongCat::~WrongCat() { std::cout << "Cat destructor called." << std::endl; }

WrongCat &WrongCat::operator=(const WrongCat &src)
{
	if (this != &src)
		this->_type = src.getType();
	std::cout << "WrongCat copy assignment operator called" << std::endl;
	return (*this);
}

// Functions
void WrongCat::makeSound() { std::cout << "meow meow😽" << std::endl; }

void WrongCat::makeSound() const { std::cout << "meow meow😽" << std::endl; }
