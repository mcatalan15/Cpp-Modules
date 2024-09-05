/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 08:03:21 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/09/05 11:11:20 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>
#include <ostream>

// Constructor and destructor
Harl::Harl(){}

Harl::~Harl(){}

/*
	This function will call the correct function depending on the level using a
	switch case. If the level is not correct, it will print an error message.

	this->Harl::debug is the syntax to call the function debug.

	The for loop will iterate through the array of function pointers and call
	the correct function.
*/
void	Harl::complain(std::string level) {

	std::string levels[4] = {"DEBUG", "INFO" "WARNING", "EXTRA"};
	int	i;
	for (i = 0; i < 4; i++)	{
		if (!levels[i].compare(level))
			break ;
	}
	switch (i) {
		case 0:
			this->Harl::debug();
		case 1:
			this->Harl::info();
		case 2:
			this->Harl::warning();
		case 3:
			this->Harl::error();
			break;
		default:
			std::cout << "Level is not correct (DEBUG, INFO, WARNING or EXTRA):" << std::endl;
	}
}

/*
	The functions debug, info, warning and error will print the corresponding message.
*/
void	Harl::debug() {
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle";
	std::cout << "-special-ketchup burger. I really do!" << std::endl;
}

void	Harl::info() {
 	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. ";
	std::cout << "You didn’t put enough bacon in my burger! ";
	std::cout << "If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning() {
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. ";
	std::cout << "I’ve been coming for years whereas you started working";
	std::cout << " here since last month." << std::endl;
}

void	Harl::error() {
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! ";
	std::cout << "I want to speak to the manager now." << std::endl;
}

