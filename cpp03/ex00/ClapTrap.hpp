/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:35:10 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/09/14 09:40:32 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <cstring>
# include <iomanip>

/*
	ClapTrap class declaration
	
	private:
		_name: name of the ClapTrap
		_hitPoints: hit points of the ClapTrap
		_energyPoints: energy points of the ClapTrap
		_attackDamage: attack damage of the ClapTrap
	
	public:
		-Ortodox canonical form
		-Getters and setters
		-attack: prints a message with the name of the ClapTrap and the target
		-takeDamage: prints a message with the name of the ClapTrap and the amount of damage taken
		-beRepaired: prints a message with the name of the ClapTrap and the amount of hit points repaired
*/

class	ClapTrap {

	private:
		std::string	_name;
		int			_hitPoints;
		int			_energyPoints;
		int			_attackDamage;

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

