/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 08:03:04 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/09/04 20:22:56 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"

/*
	This program tests the HumanA, HumanB and Weapon classes.

	Main function to test the classes first with HumanA(Bob) and then with HumanB (Jim).

	1. Create a Weapon object club with type "crude spiked club".
	2. Create a HumanA object Bob with name "Bob" and club.
	3. Bob attacks.
	4. Change the type of club to "some other type of club".
	5. Bob attacks again.
	
	We can see that the type of the weapon is changed in the second attack in the output.
*/

int	main() {
	{
		Weapon club = Weapon("crude spiked club");

		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");

		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}

	return 0;
}
