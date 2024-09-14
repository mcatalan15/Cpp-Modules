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

int main()
{

	FragTrap Empty;
	ClapTrap Pedro("PedroClap");
	ScavTrap Jon("JonScav");
	FragTrap Marc("TeoFrag");

	Marc.attack("Miami");
	Marc.takeDamage(50);
	Marc.beRepaired(30);
	Marc.highFivesGuys();

	Jon.guardGate();
	Jon.beRepaired(10);
	Jon.attack("Miami");

	Marc.takeDamage(150);
	Jon.takeDamage(150);

	Marc.takeDamage(150);

	return (0);
}
