/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:35:08 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/09/14 09:42:34 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

//Default constructor added name undefined + values on hit, energy, attack

ClapTrap::ClapTrap() : _name("undefined"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap default constructor called." << std::endl;
}

//Constructor with the correct name
ClapTrap::ClapTrap(const std::string &name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap constructor called: " << this->_name << std::endl;
}

// Copy constructor
ClapTrap::ClapTrap(const ClapTrap &src) {
	std::cout << "ClapTrap copy constructor called: " << this->_name << std::endl;
	*this = src;
}

// Destructor
ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap copy destructor called: " << this->_name << std::endl;
}

// Copy assignment operator
ClapTrap &ClapTrap::operator=(const ClapTrap &src) {
	std::cout << "ClapTrap copy assignment operator called: " << this->_name << std::endl;
	if (this != &src) {
		this->_name = src.getName();
		this->_hitPoints = src.getHitPoints();
		this->_energyPoints = src.getEnergyPoints();
		this->_attackDamage = src.getAttackDamage();
	}
	return (*this);
}

/*
	Getters to get the values of the private attributes.
*/
std::string ClapTrap::getName() const { return (_name); }

int ClapTrap::getHitPoints() const { return(_hitPoints);}

int ClapTrap::getEnergyPoints() const { return(_energyPoints);}

int ClapTrap::getAttackDamage() const { return(_attackDamage);}

/*
	Setters to get the values of the private attributes.
*/
void ClapTrap::setName(const std::string &name) { this->_name = name; }

void	ClapTrap::setHitPoints(int const hitPoints) { this->_hitPoints = hitPoints; }

void	ClapTrap::setEnergyPoints(int const energyPoints) { this->_name = energyPoints; }

void	ClapTrap::setAttackDamage(int const attackDamage) { this->_name = attackDamage; }

//Functions
/*
	Attack function:

	Simulation of an attack.
		- If the hit points are 0, the ClapTrap can not attack.
		- If the energy points are 0, the ClapTrap can not attack.
		- If the ClapTrap can attack, the energy points are reduced by 1.
*/
void	ClapTrap::attack(const std::string &target) {
	if ( this->_hitPoints == 0)
		std::cout << "ClapTrap " << this->_name << " can not attack (0 hit points)." << std::endl;
	else if (this->_energyPoints == 0)
		std::cout << "ClapTrap " << this->_name << " can not attack (0 energy points)." << std::endl;
	else {
		this->_energyPoints--;
		std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage;
		std::cout << " points of damage!" <<std::endl;

		std::cout << this->_name << " has " << this->_hitPoints << " hit points and " << this->_energyPoints;
		std::cout << " energy points." << std::endl << std::endl;
	}
}

/*
	Take damage function:

	Simulation of taking damage.
		- If the hit points are greater than 0, the ClapTrap takes damage.
		- If the hit points are less than 0, the ClapTrap has 0 hit points.
*/
void	ClapTrap::takeDamage(unsigned int amount) {
	if (this->_hitPoints > 0) {
		this->_hitPoints -= amount;
		if (this->_hitPoints < 0)
			this->_hitPoints = 0;
		std::cout << "ClapTrap " << this->_name << "has been damage with " << amount << "hit points" << std::endl;
		std::cout << this->_name << " has " << this->_hitPoints << " hit points and ";
		std::cout << this->_energyPoints << "energy points." << std::endl << std::endl;
	}
	else
		std::cout << "ClapTrap " << this->_name << " can not be damaged (0 hit points)" << std::endl << std::endl;
}

/*
	Be repaired function:

	Simulation of being repaired.
		- If the hit points are 0, the ClapTrap is repaired with the amount of hit points.
		- If the energy points are 0, the ClapTrap can not be repaired.
		- If the ClapTrap can be repaired, the energy points are increased by the amount of hit points.
*/
void	ClapTrap::beRepaired(unsigned int amount) {
	if (this->_hitPoints == 0){
		std::cout << "ClapTrap " << this->_name << " repared with " << amount << " hit points" << std::endl;
		std::cout << this->_name << " has " << this->_hitPoints << " hit points and " << this->_energyPoints;
		std::cout << " energy points" << std::endl << std::endl;
	}
	else if (this->_energyPoints == 0)
		std::cout << "ClapTrap " << this->_name << " can not be repaired (0 energy points)." << std::endl;
	else {
		this->_energyPoints += amount;
		std::cout << "ClapTrap " << this->_name << " has been repaired with ";
		std::cout << amount << " hit points!" << std::endl;
		std::cout << this->_name << " has " << this->_hitPoints << " hit points and ";
		std::cout << this->_energyPoints << " energy points." << std::endl << std::endl;
	}
}


