/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 08:03:02 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/08/16 08:03:03 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_H_
# define HUMANB_H_
# include "Weapon.hpp"

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

