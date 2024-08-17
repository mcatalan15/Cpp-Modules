/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 08:03:09 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/08/16 08:03:10 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Weapon.hpp"

//Weapon::Weapon(){}

Weapon::Weapon(std::string type) {
	this->_type = type;
}

Weapon::~Weapon(){}

//Weapon::Weapon(std::string type) {
//	this->_type = type;
//}

std::string Weapon::getType() {
	return (_type);
}

std::string Weapon::setType(std::string type) {
	this->_type = type;
	return ;
}

