/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 07:49:43 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/09/03 18:42:48 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*
	This is the constructor of the Zombie class.
	It will initialize the _name attribute of the Zombie class.
*/

Zombie::Zombie(std::string name) {
    this->_name = name;
}

/*
	This is the destructor of the Zombie class.
	It will display a message when the Zombie is destroyed.
*/

Zombie::~Zombie(void) {
    std::cout << this->_name << " has been destroyed." << std::endl;
}

/*
	This function will display a message with the name of the Zombie.
*/

void Zombie::announce(void) const {
    std::cout << this->_name << " BraiiiiiiinnzzzZ..." << std::endl;
}

