/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 09:25:36 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/09/12 09:41:02 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

// Default constructor
DiamondTrap::DiamondTrap(): ClapTrap("undefined_clap_name"), ScavTrap(_name), FragTrap(_name) {
	this->_name = "undefined";
	std::cout << "DiamondTrap default constructor called." << std::endl;
	this->_hitPoints = this->FragTrap::_hitPoints;
	this->_energyPoints = this->ScavTrap::_energyPoints;
	this->_attackDamage = this->FragTrap::_attackDamage;
}

// Constructor
DiamondTrap::DiamondTrap(const std::string &name) : ClapTrap(name + "_clap_name"), ScavTrap(_name), FragTrap(_name) {
	this->_name = name;
	std::cout << "DiamondTrap constructor called: " << this->_name << std::endl;
	this->_hitPoints = this->FragTrap::_hitPoints;
	this->_energyPoints = this->ScavTrap::_energyPoints;
	this->_attackDamage = this->FragTrap::_attackDamage;
}

// Copy constructor
DiamondTrap::DiamondTrap(const DiamondTrap &src) : ClapTrap(src.getName() + "_clap_name"), ScavTrap(src.getName()), FragTrap(src.getName()) {
	std::cout << "DiamondTrap copy constructor called: " << this->_name << std::endl;
	*this = src;
}

// Destructor
DiamondTrap::~DiamondTrap() { std::cout << "DiamondTrap Destructor called: " << this->_name << std::endl;}

// Operator =
DiamondTrap &DiamondTrap::operator=(const DiamondTrap &src) {
	std::cout << "DiamondTrap copy assigment operator: " << this->_name << std::endl;
	if (this != &src) {
		this->_name = src.getName();
		this->_hitPoints = src.FragTrap::_hitPoints;
		this->_energyPoints = src.FragTrap::_energyPoints;
		this->_attackDamage = src.FragTrap::_attackDamage;
		this->ClapTrap::_name = src.ClapTrap::getName();
	}
	return (*this);
}

void DiamondTrap::whoAmI() {
	std::cout << "WHO AM I - DiamondTrap name is: " << this->_name << std::endl;
	std::cout << "and ClapTrap name is: " << this->ClapTrap::_name << "\n" << std::endl;
}

std::string DiamondTrap::getName() const { return (_name); }
