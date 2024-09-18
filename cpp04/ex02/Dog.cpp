/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 18:07:12 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/09/17 16:35:43 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : AAnimal("dog") {
	this->_type = "dog";
	this->_brain = new Brain;
	std::cout << "Dog default constructor called." << std::endl;
}

Dog::Dog(const Dog &src) : AAnimal(src)
{
	*this = src;
	std::cout << "Dog copy constructor called." << std::endl;
}

Dog::~Dog() { delete this->_brain; std::cout << "Dog destructor called." << std::endl; }

Dog &Dog::operator=(const Dog &src)
{
	if (this != &src) {
		this->_brain = new Brain(*src._brain);
		this->_type = src.getType();
	}
	std::cout << "Dog copy assignment operator called" << std::endl;
	return (*this);
}

// getters
Brain *Dog::getBrain() const { return (_brain); }

// setters
void	Dog::setBrain(Brain *brain) { this->_brain = brain; }
// Functions
void Dog::makeSound() { std::cout << "Wouff Wouff🐶" << std::endl; }

void Dog::makeSound() const { std::cout << "Wouff Wouff🐶" << std::endl; }