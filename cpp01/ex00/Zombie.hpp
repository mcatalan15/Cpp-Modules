/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 07:49:46 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/08/16 07:49:47 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <iostream>
# include <cstring>
# include <iomanip>

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