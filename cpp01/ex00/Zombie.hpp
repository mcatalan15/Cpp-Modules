/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 07:49:46 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/09/04 18:14:21 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <iostream>
# include <cstring>
# include <iomanip>

/*
	This is the Zombie class.
	*Public:
		- Zombie the constructor of the class.
		- ~Zombie the destructor of the class.
		- void announce(void) const a function that will display a message with
		the name of the Zombie.
	*Private:
		- _name a string that will store the name of the Zombie.
*/

class Zombie {
    public:
        Zombie(std::string name);
        ~Zombie();

        void announce(void) const;
    
    private:
        std::string _name;
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif