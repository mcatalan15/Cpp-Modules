/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 08:02:37 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/08/16 08:02:38 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H
# include <iostream>
# include <cstring>
# include <iomanip>
# include <string>

class   Zombie {
    public:
        Zombie();
        Zombie(std::string name);
        ~Zombie();
        
        void    setName(std::string name);
        void    announce();
    
    private:
        std::string _name;
};

Zombie  *zombieHorde(int N, std::string name);

#endif