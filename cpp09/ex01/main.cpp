/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 12:10:23 by mcatalan@st       #+#    #+#             */
/*   Updated: 2025/01/10 12:10:26 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int argc, char **argv) {
	try {
		if (argc != 2)
			throw std::invalid_argument("Invalid number of arguments");
		RPN rpn(argv[1]);
	} catch (std::exception &e){
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
