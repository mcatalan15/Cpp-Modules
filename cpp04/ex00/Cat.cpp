/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 18:01:11 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/09/23 11:35:44 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(): Animal("cat") {
	std::cout << "Cat default constructor called." << std::endl;
}

Cat::Cat(const Cat &src) : Animal(src) {
	std::cout << "Cat copy constructor called." << std::endl;
}

// Cat::Cat(const std::string &type) : Animal(type) {
// 	std::cout << "Cat constructor called." << std::endl;
// }

Cat::~Cat() { std::cout << "Cat destructor called." << std::endl; }

Cat &Cat::operator=(const Cat &src) {
	if (this != &src)
		this->_type = src._type;
	std::cout << "Cat copy assignment operator called" << std::endl;
	return (*this);
}

// Functions
void Cat::makeSound() const { std::cout << "meow meow😽" << std::endl; }
