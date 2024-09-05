/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 08:03:26 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/09/05 11:10:07 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

/*
	This is the main function.
	It will create an instance of the Harl class.
	If the number of arguments is correct, it will call the complain function.
	If the number of arguments is not correct, it will print an error message.
*/

int	main(int argc, char **argv)
{
	Harl harl;

	if (argc == 2) {
		harl.complain(argv[1]);
	}
	else
		std::cout << "Enter a correct order: DEBUG, INFO, WARNING or ERROR" << std::endl;
	return (0);
}
