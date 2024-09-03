/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 08:03:21 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/09/03 19:23:13 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>
#include <ostream>

// Constructor and destructor

Harl::Harl(){}

Harl::~Harl(){}

/*
	This function will call the correct function depending on the level.
	If the level is not correct, it will print an error message.
	
	size() returns the number of characters in the string (format size_t) in this case 1.
	
	The for loop will iterate through the array of function pointers and call the correct function.
*/

void    Harl::complain(std::string level) {
    
    if (level.size() == 1 && level[0] >= '1' && level[0] <= '4') {
    	void (Harl::*f[4])();
		f[0] = &Harl::debug;
		f[1] = &Harl::info;
		f[2] = &Harl::warning;
		f[3] = &Harl::error;

		for (int i = 0; i < 4; i++) {
			if (i == level[0] - 49)
				(this->*f[i])();
		}
    }
    else
	    std::cout << "Level is not correct (1 to 4)." << std::endl;
}

/*
	The functions debug, info, warning and error will print the corresponding message.
*/

void    Harl::debug() {
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle";
    std::cout << "-special-ketchup burger. I really do!" << std::endl;
}

void    Harl::info() {
    std::cout << "I cannot believe adding extra bacon costs more money. ";
    std::cout << "You didn’t put enough bacon in my burger! ";
    std::cout << "If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning() {
	std::cout << "I think I deserve to have some extra bacon for free. ";
	std::cout << "I’ve been coming for years whereas you started working";
	std::cout << " here since last month." << std::endl;
}

void	Harl::error() {
	std::cout << "This is unacceptable! ";
	std::cout << "I want to speak to the manager now." << std::endl;
}

