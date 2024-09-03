/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 08:02:37 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/09/03 19:01:32 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H
# include <iostream>
# include <cstring>
# include <iomanip>
# include <string>

/*
	This class will create a Zombie.
	*Public:
		- Default constructor
		- Constructor with name
		- Destructor
		-setName(): Set the name of the Zombie
		-announce(): Announce the Zombie
	*Private:
		- _name: Name of the Zombie
*/

class   Zombie {
    public:
        Zombie();
        ~Zombie();
        
        void    setName(std::string name);
        void    announce();
    
    private:
        std::string _name;
};

Zombie  *zombieHorde(int N, std::string name);

#endif