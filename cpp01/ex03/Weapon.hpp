/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 08:03:12 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/09/04 20:41:29 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef WEAPON_H_
# define WEAPON_H_
# include <iostream>
# include <cstring>
# include <iomanip>

/*
	Weapon class declaration.
	*Public:
		- Constructor: Initializes the type of the weapon.
		- Destructor: Default destructor.
		- getType: Returns the type of the weapon.
		- setType: Sets the type of the weapon.
	*Private:
		- _type: Type of the weapon.
*/

class	Weapon	{

	public:
		Weapon(std::string type);
		~Weapon();

		std::string getType();
		void	setType(std::string type);

	private:
		std::string _type;
};

#endif
