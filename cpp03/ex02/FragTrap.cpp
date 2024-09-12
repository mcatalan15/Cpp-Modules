#include "FragTrap.hpp"

// Default constructor
FragTrap::FragTrap(): ClapTrap() {
	std::cout << "FragTrap default constructor called." << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

// Constructor
FragTrap::FragTrap(const std::string &name) : ClapTrap(name) {
	std::cout << "FragTrap construcor called: " << this->_name << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

// Copy constructor
FragTrap::FragTrap(const FragTrap &src) : ClapTrap(src) {
	std::cout << "FragTrap copy constructor called: " << this->_name << std::endl;
	*this = src;
}

// Destructor
FragTrap::~FragTrap() { std::cout << "FragTrap Destructor called: " << this->_name << std::endl;}

// Operator =
FragTrap &FragTrap::operator=(const FragTrap &src) {
	std::cout << "FragTrap copy assigment operator: " << this->_name << std::endl;
	if (this != &src) {
		this->_name = src.getName();
		this->_hitPoints = src.getHitPoints();
		this->_energyPoints = src.getEnergyPoints();
		this->_attackDamage = src.getAttackDamage();
	}
	return (*this);
}

void FragTrap::highFivesGuys() {
	std::cout << "FragTrap" << this->_name << " has High Fives US! 🖐️";
	std::cout << std::endl << std::endl;
}

