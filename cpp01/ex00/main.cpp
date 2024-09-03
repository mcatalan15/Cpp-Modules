/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 07:49:25 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/09/03 18:38:14 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*
	This is the main function that will run the program.
	It will create a Zombie on the stack and on the heap.
	It will display the Zombie on the stack and on the heap.
*/

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