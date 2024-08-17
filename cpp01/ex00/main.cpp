/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 07:49:25 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/08/16 07:49:26 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Zombie.hpp"

int main()
{
   Zombie *zom;

   Zombie zombie_clas = Zombie("Zombie");
   zombie_clas.announce();

   zom = newZombie("Heap");

   randomChump("Stack:");

   zom->announce();

   delete zom;
   return 0;
}