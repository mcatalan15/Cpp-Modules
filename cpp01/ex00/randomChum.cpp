/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChum.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 07:49:39 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/09/03 18:42:20 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*
	This function will create a new Zombie on the stack.
	It will display the Zombie.
	
	What is the stack?
	The stack is a region of memory that is managed automatically. When you declare
	a variable on the stack, the memory is automatically allocated and when the
	variable goes out of scope, the memory is automatically deallocated.
*/

void randomChump(std::string name)
{
    Zombie chump = Zombie(name);
    chump.announce();
}
