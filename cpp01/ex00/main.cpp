/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 07:49:25 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/09/02 18:00:20 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Zombie.hpp"

int main()
{
   Zombie *zom;

   Zombie zombie_clas = Zombie("Zombie");
   zombie_clas.announce();

   std::cout <<"Zombie allocated on the heap " << std::endl;
   zom = newZombie("Heap");

   std::cout << "Zombie allocated on the stack " << std::endl;
   randomChump("Stack:");

   zom->announce();

   delete zom;
   return 0;
}