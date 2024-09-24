/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 17:36:26 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/09/17 16:31:02 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal() : _type("undefined") {
	std::cout << "AAnimal default constructor called. Type:" << this->getType() << std::endl;
}

AAnimal::AAnimal(const std::string &type) : _type(type) {
	std::cout << "AAnimal constructor called. Type:" << this->getType() << std::endl;
}

AAnimal::AAnimal(const AAnimal &src) : _type(src._type) {
	std::cout << "AAnimal copy constructor called. Type:" << this->getType() << std::endl;
}

AAnimal::~AAnimal() {
	std::cout << "AAnimal destructor called. Type:" << this->getType() << std::endl;
}

// operator "="
AAnimal &AAnimal::operator=(const AAnimal &src)
{
	if (this != &src)
		this->_type = src._type;
	std::cout << "AAnimal copy assignment operator called.Type: " << this->getType() << std::endl;
	return (*this);
}

// GETTER
std::string AAnimal::getType() const { return(_type); }

// SETTER
void AAnimal::setType(const std::string &type) { _type = type; }

void AAnimal::makeSound() const{ std::cout << "...Silence..." << std::endl; }