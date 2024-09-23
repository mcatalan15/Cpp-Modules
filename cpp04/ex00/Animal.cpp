/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 17:36:26 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/09/23 11:30:56 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() {
	this->_type = "undefined";
	std::cout << "Animal default constructor called. Type:" << this->getType() << std::endl;
}

Animal::Animal(const std::string &type) {
	this->_type = type;
	std::cout << "Animal constructor called. Type:" << this->getType() << std::endl;
}

Animal::Animal(const Animal &src) {
	*this = src;
	std::cout << "Animal copy constructor called. Type:" << this->getType() << std::endl;
}

Animal::~Animal() {
	std::cout << "Animal destructor called. Type:" << this->getType() << std::endl;
}

// operator "="
Animal &Animal::operator=(const Animal &src)
{
	std::cout << "Animal copy assignment operator called.Type: " << this->getType() << std::endl;
	if (this != &src)
		this->_type = src.getType();
	return (*this);
}

// GETTER
std::string Animal::getType() const { return(_type); }
// SETTER
void Animal::setType(const std::string &type) { this->_type = type; }

// FUNCTIONS
void Animal::makeSound() { std::cout << "...Silence..." << std::endl; }
void Animal::makeSound() const{ std::cout << "...Silence..." << std::endl; }
