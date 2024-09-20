/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:35:13 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/09/14 09:40:58 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ClapTrap.hpp"

/*
	ClapTrap main function
	-Create two ClapTrap objects
	-Attack and repair them
*/

int main(void) {
	std::cout << "---- Start ----" << std::endl;
	{
	std::cout << "---- Alone ----" << std::endl;
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
	Jon.attack("11");
	Jon.beRepaired(15);
	std::cout << std::endl << std::endl << std::endl;
	}
	{
	std::cout << "---- Both ----" << std::endl;
	ClapTrap Elon("Elon");
	ClapTrap Mark("Mark");

	Elon.setAttackDamage(3);
	Mark.setAttackDamage(1);

	Elon.attack(Mark.getName());
	Mark.takeDamage(Elon.getAttackDamage());

	Mark.attack(Elon.getName());
	Elon.takeDamage(Mark.getAttackDamage());

	Mark.attack(Elon.getName());
	Elon.takeDamage(Mark.getAttackDamage());

	if (Elon.getHitPoints() < Mark.getHitPoints())
		std::cout << "Mark wins!" << std::endl;
	else if (Elon.getHitPoints() > Mark.getHitPoints())
		std::cout << "Elon wins!" << std::endl;
	else
		std::cout << "It's a tie!" << std::endl;
	std::cout << std::endl;
	}
	std::cout << "---- End ----" << std::endl;
	return (0);
}
