/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 18:01:11 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/09/13 18:49:17 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(): Animal("cat"), _brain(new Brain()) {
	std::cout << "Cat default constructor called." << std::endl;
}

Cat::Cat(const Cat &src) : Animal(src), _brain(new Brain(*src._brain)) {
	std::cout << "Cat copy constructor called." << std::endl;
}

Cat::~Cat() { delete this->_brain; std::cout << "Cat destructor called." << std::endl; }

Cat &Cat::operator=(const Cat &src) {
	if (this != &src) {
		delete this->_brain;
		this->_brain = new Brain(*src._brain);
		this->_type = src.getType();
	}
	std::cout << "Cat copy assignment operator called" << std::endl;
	return (*this);
}

// getters
Brain *Cat::getBrain() const { return (_brain); }

// setters
void	Cat::setBrain(Brain *brain) {
	if (this->_brain != brain) {
		delete this->_brain;
		this->_brain = brain;
	}
 }

// Functions
void Cat::makeSound() const { std::cout << "meow meow😽" << std::endl; }
