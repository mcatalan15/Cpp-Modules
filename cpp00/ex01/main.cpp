/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 07:50:30 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/09/03 18:31:52 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

/*
	This is the main function that will run the program.
	It will display the options and will call the functions
	to ADD a contact, SEARCH a contact or EXIT the program.
*/

int	main(void){

	std::string	input;
	PhoneBook	obj;

	// print_options();
	std::cout << "Enter one of these options:" << std::endl;
	std::cout << "\tADD (save a new contact)" << std::endl;
	std::cout << "\tSEARCH (display a specific contact)" << std::endl;
	std::cout << "\tEXIT (the program quits and the contacts are lost forever!)" << std::endl;

	while (1) {
		std::cout << ">>";
		if (!std::getline(std::cin, input))
			return 1;
		if (input == "ADD")
			obj.addContact();
		else if (input == "SEARCH")
			obj.searchContact();
		else if (input == "EXIT") {
			std::cout << "Exiting...." << std::endl;
			break ;
		}
		else
			std::cout << "Not a correct option. Type again" << std::endl;
	}
	std::cout << "BYE" << std::endl;
	return 0;
}
