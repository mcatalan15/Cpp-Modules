/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:35:10 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/09/14 09:44:14 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <cstring>
# include <iomanip>

/*
	ClapTrap class declaration

	Why protected?
	-Protected members are accessible in the class and in the derived class.
	-Private members are only accessible in the class.
	This means that the derived class can access the protected members of the base class.
	
	The rest of the class is the same as in ex00
*/

class	ClapTrap {

	protected:
		std::string	_name;
		int		_hitPoints;
		int		_energyPoints;
		int		_attackDamage;

	public:
		ClapTrap();
		ClapTrap(const std::string &name);
		ClapTrap(const ClapTrap &src);
		~ClapTrap();
		ClapTrap &operator=(const ClapTrap &src);

		std::string	getName() const;
		int		getHitPoints() const;
		int		getEnergyPoints() const;
		int		getAttackDamage() const;

		void		setName(const std::string &name);
		void		setHitPoints(int const hitPoints);
		void		setEnergyPoints(int const energyPoints);
		void		setAttackDamage(int const attackDamage);

		void		attack(const std::string &target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);
};

#endif

