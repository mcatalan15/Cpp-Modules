/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 11:16:20 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/12/09 11:18:22 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

int main(int argc, char **argv) {
	if (argc == 2) {
		try {
			ScalarConverter::convert(argv[1]);
/* 			ScalarConverter::convert("c");
			ScalarConverter::convert("a");
			ScalarConverter::convert("0");
			ScalarConverter::convert("-42");
			ScalarConverter::convert("42");
			ScalarConverter::convert("0.0f");
			ScalarConverter::convert("-4.2f");
			ScalarConverter::convert("4.2f");
			ScalarConverter::convert("-inff");
			ScalarConverter::convert("+inff");
			ScalarConverter::convert("+nanf");
			ScalarConverter::convert("0.0");
			ScalarConverter::convert("-4.2");
			ScalarConverter::convert("4.2");
			ScalarConverter::convert("-inf");
			ScalarConverter::convert("+inff");
			ScalarConverter::convert("nan");
 			ScalarConverter::convert("2147483647");
			std::cout << std::endl;
			ScalarConverter::convert("2147483648");
			std::cout << std::endl;
			ScalarConverter::convert("-2147483648");
			std::cout << std::endl;
			ScalarConverter::convert("-2147483649");
			std::cout << std::endl;	*/		
		}
		catch(const std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
	}
	else
		std::cerr << "Error - Invalid number of arguments." << std::endl;
	return (0);
}
