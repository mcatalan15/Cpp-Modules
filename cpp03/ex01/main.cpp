/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:35:13 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/09/17 16:17:58 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

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

int main()
{
	ClapTrap Fernando("Fernando");
	ScavTrap Tony("Tony");

	std::cout << std::endl;
	std::cout << "ScavTrap attack: " << Tony.getAttackDamage() << std::endl; 
	std::cout << "ScavTrap hit points: " << Tony.getHitPoints() << std::endl;
	std::cout << "ScavTrap energy: " << Tony.getEnergyPoints() << std::endl;
	
	Fernando.setAttackDamage(3);
	std::cout << std::endl;

	Fernando.attack(Tony.getName());
	Tony.takeDamage(Fernando.getAttackDamage());
	Tony.attack(Fernando.getName());
	Fernando.takeDamage(Tony.getAttackDamage());
	Fernando.attack(Tony.getName());
	Tony.setEnergyPoints(0);
	Tony.attack(Fernando.getName());

	Tony.guardGate();
	std::cout << std::endl;
	return 0;
}
