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

AAnimal::AAnimal() {
	this->_type = "undefined";
	std::cout << "Animal default constructor called. Type:" << this->getType() << std::endl;
}

AAnimal::AAnimal(const std::string &type) {
	this->_type = type;
	std::cout << "Animal constructor called. Type:" << this->getType() << std::endl;
}

AAnimal::AAnimal(const AAnimal &src) {
	*this = src;
	std::cout << "Animal copy constructor called. Type:" << this->getType() << std::endl;
}

AAnimal::~AAnimal() {
	std::cout << "Animal destructor called. Type:" << this->getType() << std::endl;
}

// operator "="
AAnimal &AAnimal::operator=(const AAnimal &src)
{
	if (this != &src)
	{
		this->_type = src.getType();
	}
	std::cout << "Animal copy assignment operator called.Type: " << this->getType() << std::endl;
	return (*this);
}

// GETTER
std::string AAnimal::getType() const { return(_type); }
// SETTER
void AAnimal::setType(const std::string &type) { this->_type = type; }
