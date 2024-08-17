/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 07:49:37 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/08/16 07:49:38 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Zombie.hpp"

Zombie  *newZombie(std::string name)
{
    Zombie *zombieNew = new Zombie(name);
    return (zombieNew);
}
