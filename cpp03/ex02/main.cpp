/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:35:13 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/09/14 09:52:23 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

/*
	main function:
		- Create two instances of the ClapTrap class.
		- Set the attack damage of the first instance to 2.
		- Call the attack function of the first instance.
		- Call the take damage function of the second instance.
		- Call the attack function of the second instance.
		- Call the take damage function of the first instance.
		- Call the attack function of the first instance.
		- Set the energy points of the second instance to 0.
		- Call the attack function of the second instance.
		- Call the guard gate function of the second instance.
*/

int main() {
	std::cout << "---- Start ----" << std::endl;
	{
		std::cout << "---- Alone ----" << std::endl;
		FragTrap Empty;
		ClapTrap Pedro("PedroClap");
		ScavTrap Jon("JonScav");
		FragTrap Marc("MarcFrag");

		Marc.attack("Miami");
		Marc.takeDamage(50);
		Marc.beRepaired(30);
		Marc.highFivesGuys();

		Jon.guardGate();
		Jon.beRepaired(10);
		Jon.attack("Francia");

		Marc.takeDamage(150);
		Jon.takeDamage(150);

		Marc.takeDamage(150);
		std::cout << std::endl << std::endl << std::endl;
	}
	{
		std::cout << "---- Both ----" << std::endl;
		ClapTrap Fernando("Fernando");
		ScavTrap Tony("Tony");
		FragTrap Kim("Kim");

		std::cout << std::endl;
		std::cout << "ScavTrap attack: " << Tony.getAttackDamage() << std::endl; 
		std::cout << "ScavTrap hit points: " << Tony.getHitPoints() << std::endl;
		std::cout << "ScavTrap energy: " << Tony.getEnergyPoints() << std::endl;
		
		Kim.highFivesGuys();

		Fernando.setAttackDamage(3);
		std::cout << std::endl;

		Fernando.attack(Tony.getName());
		Tony.takeDamage(Fernando.getAttackDamage());
		Tony.attack(Fernando.getName());
		Fernando.takeDamage(Tony.getAttackDamage());
		Fernando.attack(Tony.getName());
		std::cout << "hohoodogfofgdohfgohfod" << std::endl << std::endl;
		
		Tony.attack(Kim.getName());
		Kim.takeDamage(Kim.getAttackDamage());
		Kim.attack(Tony.getName());
		Tony.takeDamage(Tony.getAttackDamage());

		Tony.setEnergyPoints(0);
		Tony.attack(Fernando.getName());
		
		Tony.guardGate();
		std::cout << std::endl;
	}
	return (0);
}
