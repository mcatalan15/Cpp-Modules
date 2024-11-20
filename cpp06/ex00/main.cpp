/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 12:54:16 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/11/20 19:36:46 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

/*
	This main function check the num of arguments and call the convert function
*/

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Error: invalid number of arguments" << std::endl;
		return 1;
	}
	Converter::convert(argv[1]);
	return 0;
}
