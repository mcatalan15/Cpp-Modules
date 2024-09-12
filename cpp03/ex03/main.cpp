/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:35:13 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/09/12 09:43:20 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{

	std::cout << "---- Diamond Constructor ----" << std::endl
			  << std::endl;

	DiamondTrap Julia("Julia");

	std::cout << "---- Diamond actions ----" << std::endl
			  << std::endl;

	Julia.whoAmI();
	Julia.takeDamage(50);
	Julia.beRepaired(10);
	Julia.attack("Sevilla");
	Julia.takeDamage(120);
	Julia.attack("Marte");

	std::cout << "---- New constructor ----" << std::endl
			  << std::endl;

	DiamondTrap David("David");

	std::cout << "---- = operator ----" << std::endl
			  << std::endl;

	David = Julia;
	std::cout << David.getName() << " has " << David.getEnergyPoints() << " energy points" << std::endl;
	std::cout << David.getName() << " has " << David.getHitPoints() << " hit points" << std::endl
			  << std::endl;

	std::cout << "---- Copy assignment ----" << std::endl
			  << std::endl;

	DiamondTrap Pepe(David);
	std::cout << Pepe.getName() << " has " << Pepe.getEnergyPoints() << "energy points" << std::endl;
	std::cout << Pepe.getName() << " has " << Pepe.getHitPoints() << "hit points" << std::endl
			  << std::endl;

	std::cout << "---- Constructor with pointer ----" << std::endl
			  << std::endl;

	ClapTrap *ptr = new DiamondTrap("Ju");
	delete ptr;

	std::cout << "---- Destructors ----" << std::endl
			  << std::endl;

	return (0);
}

// int main()
// {

// 	FragTrap Empty;
// 	ClapTrap Julia("JuliaClap");
// 	ScavTrap Pepe("PepeScav");
// 	FragTrap Teo("TeoFrag");

// 	Teo.attack("Miami");
// 	Teo.takeDamage(50);
// 	Teo.beRepaired(30);
// 	Teo.highFivesGuys();

// 	Pepe.guardGate();
// 	Pepe.beRepaired(10);
// 	Pepe.attack("Miami");

// 	Teo.takeDamage(150);
// 	Pepe.takeDamage(150);

// 	Teo.takeDamage(150);

// 	return (0);
// }

// int main( ) {

// 	ClapTrap Julia("Julia");
// 	ScavTrap Pepe("Pepe");
// 	ScavTrap Empty;

// 	ScavTrap Teo("Teo");

// 	Pepe.attack("Miami");
// 	Teo.takeDamage(50);
// 	Pepe.beRepaired(3);

// 	Teo.guardGate();

// 	Pepe.beRepaired(3);

// 	Pepe.beRepaired(5);
// 	Pepe.attack("Miami");
// 	Pepe.attack("Miami");
// 	Pepe.attack("Miami");
// 	Pepe.attack("Miami");

// 	Teo.takeDamage(5);
// 	Teo.takeDamage(10);
// 	Teo.takeDamage(7);

// 	return (0);
// }

/*
int main(void) {
	
	ClapTrap Marc("Marc");
	ClapTrap Jon("Jon");

	Marc.attack("Bin Laden");
	Marc.beRepaired(3);
	Marc.takeDamage(5);
	Marc.attack("Stalin");
	Marc.beRepaired(100);

	Jon.attack("Fidel Castro");
	Jon.attack("2");
	Jon.attack("3");
	Jon.attack("4");
	Jon.attack("5");
	Jon.attack("6");
	Jon.attack("7");
	Jon.attack("8");
	Jon.attack("9");
	Jon.attack("10");
	Jon.beRepaired(15);

	return (0);
}
*/
