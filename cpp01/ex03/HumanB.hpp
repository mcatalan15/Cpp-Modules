/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 08:03:02 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/09/04 20:40:36 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_H_
# define HUMANB_H_
# include "Weapon.hpp"

/*
	HumanB class declaration.
	*Public:
		- Constructor: Initializes the name of the HumanB object.
		- Destructor: Default destructor.
		- getName: Returns the name of the HumanB object.
		- setWeapon: Sets the weapon of the HumanB object (the & symbol is used to pass the object by reference).
		- attack: Prints the name of the HumanB object and the type of weapon they are using.
	*Private:
		- _name: Name of the HumanB object.
		- _weaponB: Pointer to a Weapon object (that is why we use the * symbol).
*/

class	HumanB {

	public:
		HumanB(std::string name);
		~HumanB();

		std::string	getName();
		void		setWeapon(Weapon &weapon);
		void		attack();

	private:
		std::string	_name;
		Weapon		*_weaponB;
};

#endif

