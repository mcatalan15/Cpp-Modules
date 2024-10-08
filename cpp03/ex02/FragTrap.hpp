/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 09:53:24 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/09/14 09:53:25 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>
#include <cstring>
#include <iomanip>
#include "ClapTrap.hpp"

// FragTrap class declaration same way as ScavTrap

class	FragTrap: public ClapTrap {

	public:
		FragTrap();
		FragTrap(const std::string &name);
		FragTrap(const FragTrap &src);
		~FragTrap();

		FragTrap &operator=(const FragTrap &src);

		void highFivesGuys(void);
};

#endif
