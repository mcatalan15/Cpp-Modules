/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 08:02:35 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/09/03 18:59:01 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Default constructor

Zombie::Zombie(){}

// Destructor

Zombie::~Zombie(void) {
    std::cout << this->_name << " has been destroyed." << std::endl;
}

// Set the name of the Zombie

void    Zombie::setName(std::string name) {
    this->_name = name;
}

// Announce the Zombie

void Zombie::announce() {
    std::cout << this->_name << " BraiiiiiiinnzzzZ..." << std::endl;
}