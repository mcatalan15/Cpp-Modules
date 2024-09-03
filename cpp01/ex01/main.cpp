/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 08:02:29 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/09/03 18:56:24 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
 
/*
 	This function will create a horde of Zombies on the heap.
 	It will return the first Zombie of the horde.

	In this project, we will use the heap to store the Zombies.

	We  can see a pointer as a variable that stores the address of another variable.
	Then we create a for loop that will create a Zombie for each element of the array.
	We will use the pointer to access the elements of the array.
	We will use the new keyword to create the array of Zombies on the heap.
	We will use the delete[] keyword to delete the array of Zombies from the heap.
*/

int main() {
    Zombie *zombiePtr;
    
    int N = 15;
    zombiePtr = zombieHorde(N, "Roberto");
    for (int i = 0; i < N; i++) {
        std::cout << "Zombie num " << i+1 << " announcement:" << std::endl;
        zombiePtr[i].announce();
    }
    
    delete[] zombiePtr;
    
    return 0;
}
