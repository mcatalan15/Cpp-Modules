/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 08:02:59 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/09/04 20:38:36 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

/*
	Constructor for HumanB class.
	Initializes the name of the HumanB object with the given value.
*/

HumanB::HumanB(std::string name) : _name(name) {
	this->_name = name;
	this->_weaponB = NULL;
}

// Destructor for HumanB class.

HumanB::~HumanB() {}

/*
	Return the name of the HumanB object.
*/

std::string HumanB::getName() {
	return (_name);
}

/*
	Set the weapon of the HumanB object with the given value.
*/

void	HumanB::setWeapon(Weapon &weapon) {
	this->_weaponB = &weapon;
}

/*
	Attack function for HumanB class.
	Prints the name of the HumanB object and the type of weapon they are using.
*/

void	HumanB::attack() {
	if (this->_weaponB == NULL)
		std::cout << "No weapon" << std::endl;
	else
		std::cout << this->_name << " attacks with their" << _weaponB->getType() << std::endl;
}

