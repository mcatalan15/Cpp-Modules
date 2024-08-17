/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 08:02:40 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/08/16 08:02:41 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name) {    
    Zombie *zombieNew = new Zombie[N];
    
    for (int i = 0; i < N; i++)
        zombieNew[i].setName(name);
    return zombieNew;
}