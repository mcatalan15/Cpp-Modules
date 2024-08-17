/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 08:02:53 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/08/17 15:09:57 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon): _name(name), _weaponA(weapon)	{}

HumanA::~HumanA() {}

void	HumanA::attack() {
	std::cout << this->_name << " attack with their " << _weaponA.getType() << std::endl;
}

