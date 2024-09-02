/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 08:03:26 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/08/16 08:03:27 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

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

