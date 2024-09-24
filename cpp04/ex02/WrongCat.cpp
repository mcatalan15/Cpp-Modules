/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 18:14:29 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/09/13 18:15:13 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("cat") {
	std::cout << "Cat default constructor called." << std::endl;
}

WrongCat::WrongCat(const WrongCat &src) : WrongAnimal(src) {
	std::cout << "Cat copy constructor called." << std::endl;
}

WrongCat::~WrongCat() { std::cout << "Cat destructor called." << std::endl; }

WrongCat &WrongCat::operator=(const WrongCat &src)
{
	if (this != &src)
		this->_type = src._type;
	std::cout << "Cat copy assignment operator called" << std::endl;
	return (*this);
}

// Functions
void WrongCat::makeSound() const { std::cout << "meow meow😽" << std::endl; }
