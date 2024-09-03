/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 07:49:37 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/09/03 18:41:45 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*
	This function will create a new Zombie on the heap.
	It will return the new Zombie.

	What is the heap? 
	The heap is a region of memory that is not managed automatically. You are
	responsible for managing it, specifically to free the memory you have allocated
	with the delete operator. when you are done with it.
*/

Zombie  *newZombie(std::string name)
{
    Zombie *zombieNew = new Zombie(name);
    return (zombieNew);
}
