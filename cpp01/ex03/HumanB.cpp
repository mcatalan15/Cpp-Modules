/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 08:02:59 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/08/16 08:03:00 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name) {
	this->_name = name;
	this->_weaponB = NULL;
}

HumanB::~HumanB() {}

std::string HumanB::getName() {
	return (_name);
}

void	HumanB::setWeapon(Weapon &weapon) {
	this->_weaponB = &weapon;
}

void	HumanB::attack() {
	if (this->_weaponB == NULL)
		std::cout << "No weapon" << std::endl;
	else
		std::cout << this->_name << " attacks with their" << _weaponB->getType() << std::endl;
}

