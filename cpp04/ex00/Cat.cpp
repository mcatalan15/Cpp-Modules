/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 18:01:11 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/09/13 18:06:57 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(): Animal("cat") {
	this->_type = "cat";
	std::cout << "Cat default constructor called." << std::endl;
}

Cat::Cat(const Cat &src) : Animal(src) {
	*this = src;
	std::cout << "Cat copy constructor called." << std::endl;
}

Cat::~Cat() { std::cout << "Cat destructor called." << std::endl; }

Cat &Cat::operator=(const Cat &src) {
	if (this != &src)
		this->_type = src.getType();
	std::cout << "Cat copy assignment operator called" << std::endl;
	return (*this);
}

// Functions
void Cat::makeSound() { std::cout << "meow meow😽" << std::endl; }

void Cat::makeSound() const { std::cout << "meow meow😽" << std::endl; }
