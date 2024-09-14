/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 18:07:12 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/09/13 18:17:58 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("dog")
{
	this->_type = "dog";
	std::cout << "Dog default constructor called." << std::endl;
}

Dog::Dog(const Dog &src) : Animal(src)
{
	*this = src;
	std::cout << "Dog copy constructor called." << std::endl;
}

Dog::~Dog() { std::cout << "Dog destructor called." << std::endl; }

Dog &Dog::operator=(const Dog &src)
{
	if (this != &src)
		this->_type = src.getType();
	std::cout << "Dog copy assignment operator called" << std::endl;
	return (*this);
}

// Functions
void Dog::makeSound() { std::cout << "Wouff Wouff🐶" << std::endl; }

void Dog::makeSound() const { std::cout << "Wouff Wouff🐶" << std::endl; }