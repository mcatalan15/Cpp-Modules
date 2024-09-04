/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 08:02:57 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/09/04 20:24:56 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef HUMANA_H_
# define HUMANA_H_
# include "Weapon.hpp"

/*
	HumanA class definition.
	Contains the name of the HumanA object and a reference to a Weapon object.
	*Public:
		- Constructor: Initializes the name and weapon of the HumanA object.
		- Destructor: Default destructor.
		- attack: Prints the name of the HumanA object and the type of weapon they are using.
	*Private:
		- _name: Name of the HumanA object.
		- _weaponA: Reference to a Weapon object (that is why we use the & symbol).
*/

class	HumanA {
	
	public:
		HumanA(std::string name, Weapon &weapon);
		~HumanA();

		void	attack();
	private:
		std::string	_name;
		Weapon		&_weaponA;
};

#endif
