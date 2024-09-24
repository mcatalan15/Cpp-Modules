/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 18:35:17 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/09/13 19:00:58 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() : _index(-1){
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain &src) {
	*this = src;
	std::cout << "Brain copy constructor called" << std::endl;
}

Brain::~Brain() { std::cout <<"Brain Destructor called" <<std::endl; }

Brain &Brain::operator=(const Brain &src) {
	if (this != &src) {
		this->_index = src._index;
		for (int i = 0; i <= this->_index; i++) {
			this->_ideas[i] = src._ideas[i];
		}
	}
	std::cout << "Brain copy assigment operator called." << std::endl;
	return (*this);
}

// getter
std::string Brain::getIdea() const {
	if (this->_index < 0 || this->_index >= 100) {
		std::cout << "Invalid index. There are no ideas in brain." << std::endl;
		return ("");
	}
	return (this->_ideas[this->_index]);
}

// setter
void	Brain::setIdea(const std::string &idea) {
	if (this->_index >= 99) {
		std::cout << "You can not add more ideas." << std::endl;
		return ;
	}
	this->_ideas[++this->_index] = idea;
}

void	Brain::printIdeas() {
	if (this->_index < 0) {
		std::cout << "There are no ideas in brain." << std::endl;
		return ;
	}
	for (int i = 0; i <= this->_index; i++)
		std::cout << "Idea " << i + 1 << ": " << this->_ideas[i] << std::endl;
}
