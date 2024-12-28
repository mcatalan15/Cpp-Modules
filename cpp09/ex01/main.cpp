/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:16:41 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/12/19 11:20:46 by mcatalan@st      ###   ########.fr       */
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
