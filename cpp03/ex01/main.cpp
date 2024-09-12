/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:35:13 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/09/09 19:35:42 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ClapTrap.hpp"
# include "ScavTrap.hpp"

#include "ClapTrap.hpp"
#include "ScavTrap.hpp" 

int main( ) {

	ClapTrap Julia("Julia");
	ScavTrap Pepe("Pepe");
	ScavTrap Empty;

	ScavTrap Teo("Teo");

	Pepe.attack("Miami");
	Teo.takeDamage(5);
	Pepe.beRepaired(3);

	Teo.guardGate();

	Pepe.beRepaired(3);

	Pepe.beRepaired(5);
	Pepe.attack("Miami");
	Pepe.attack("Miami");
	Pepe.attack("Miami");
	Pepe.attack("Miami");

	Teo.takeDamage(5);
	Teo.takeDamage(10);
	Teo.takeDamage(7);

	return (0);
}

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
