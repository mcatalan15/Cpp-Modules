/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 09:45:04 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/09/14 09:47:59 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include <cstring>
#include <iomanip>
#include "ClapTrap.hpp"

/*
	ScavTrap class declaration

	Why public?
	-ScavTrap is a derived class of ClapTrap
	-ScavTrap inherits the public and protected members of ClapTrap
	-ScavTrap can access the public members of ClapTrap
	-ScavTrap can access the protected members of ClapTrap
	-ScavTrap can't access the private members of ClapTrap (that's why we use protected in ClapTrap)
*/

class	ScavTrap: public ClapTrap {

	public:
		ScavTrap();
		ScavTrap(const std::string &name);
		ScavTrap(const ScavTrap &src);
		~ScavTrap();

		ScavTrap &operator=(const ScavTrap &src);

		void guardGate();
};

#endif
