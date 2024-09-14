/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 09:44:52 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/09/14 09:47:02 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// Default constructor
ScavTrap::ScavTrap(): ClapTrap() {
	std::cout << "ScavTrap default constructor called." << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

// Constructor
ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name) {
	std::cout << "ScavTrap construcot called: " << this->_name << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

// Copy constructor
ScavTrap::ScavTrap(const ScavTrap &src) : ClapTrap(src) {
	std::cout << "ScavTrap copy constructor called: " << this->_name << std::endl;
	*this = src;
}

// Destructor
ScavTrap::~ScavTrap() { std::cout << "ScavTrap Destructor called: " << this->_name << std::endl;}

// Copy assignment operator
ScavTrap &ScavTrap::operator=(const ScavTrap &src) {
	std::cout << "ScavTrap copy assigment operator: " << this->_name << std::endl;
	if (this != &src) {
		this->_name = src.getName();
		this->_hitPoints = src.getHitPoints();
		this->_energyPoints = src.getEnergyPoints();
		this->_attackDamage = src.getAttackDamage();
	}
	return (*this);
}

/*
	Guard Gate member function
	Prints the name of the ScavTrap and the message "is in Gate keeper mode."
*/
void ScavTrap::guardGate() {
	std::cout << "ScavTrap " << this->_name << " is in Gate keeper mode.";
	std::cout << std::endl << std::endl;
}

