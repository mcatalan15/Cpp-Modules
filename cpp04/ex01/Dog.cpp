/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 18:07:12 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/09/13 18:53:07 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("dog"), _brain(new Brain()) {
	std::cout << "Dog default constructor called." << std::endl;
}

Dog::Dog(const Dog &src) : Animal(src), _brain(new Brain(*src._brain)) {
	std::cout << "Dog copy constructor called." << std::endl;
}

Dog::~Dog() { delete this->_brain; std::cout << "Dog destructor called." << std::endl; }

Dog &Dog::operator=(const Dog &src)
{
	if (this != &src) {
		delete this->_brain;
		this->_brain = new Brain(*src._brain);
		this->_type = src.getType();
	}
	std::cout << "Dog copy assignment operator called" << std::endl;
	return (*this);
}

// getters
Brain *Dog::getBrain() const { return (_brain); }

// setters
void	Dog::setBrain(Brain *brain) {
	if (this->_brain != brain) {
		delete this->_brain;
		this->_brain = brain;
	}
}

// Functions
void Dog::makeSound() const { std::cout << "Wouff Wouff🐶" << std::endl; }