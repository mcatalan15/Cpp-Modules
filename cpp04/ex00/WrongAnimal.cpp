/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 18:12:12 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/09/20 17:11:22 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("undefined") {
	std::cout << "WrongAnimal default constructor called. Type: " << this->getType() << std::endl;
}

WrongAnimal::WrongAnimal(const std::string type) : _type(type) {
	std::cout << "WrongAnimal constructor called. Type: " << this->getType() << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &src) : _type(src._type) {
	std::cout << "WrongAnimal copy constructor called. Type: " << this->getType() << std::endl;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal destructor called. Type: " << this->getType() << std::endl;
}

// operator "="
WrongAnimal &WrongAnimal::operator=(const WrongAnimal &src)
{
	if (this != &src)
		this->_type = src._type;
	std::cout << "WrongAnimal copy assignment operator called.Type: " << this->getType() << std::endl;
	return (*this);
}

// GETTER
std::string WrongAnimal::getType() const { return (_type); }
// SETTER
void WrongAnimal::setType(const std::string &type) { _type = type; }

// FUNCTIONS
void WrongAnimal::makeSound() const { std::cout << "...Silence..." << std::endl; }
