/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 08:02:53 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/09/04 20:23:44 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

/*
	Constructor for HumanA class.
	Initializes the name and weapon of the HumanA object with the given values.
*/

HumanA::HumanA(std::string name, Weapon &weapon): _name(name), _weaponA(weapon)	{}

// Destructor for HumanA class.

HumanA::~HumanA() {}

/*
	Attack function for HumanA class.
	Prints the name of the HumanA object and the type of weapon they are using.
*/

void	HumanA::attack() {
	std::cout << this->_name << " attack with their " << _weaponA.getType() << std::endl;
}

