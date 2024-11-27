/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 12:54:18 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/11/20 19:52:58 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"
#include <iostream>
#include <cstdlib>
#include <climits>
#include <cfloat>

using std::string;

// Default constructor
Converter::Converter() {}

// Copy constructor
Converter::Converter(const Converter &src) { *this = src; }

// Destructor
Converter::~Converter() {}

// Assignment operator "="
Converter &Converter::operator=(const Converter &src) { (void)src; return (*this); }

// Helper: Is valid double
static bool isValidDouble(const string &input, double &value) {
    if (input.length() == 3 && input[0] == '\'' && input[2] == '\'') {
        value = static_cast<double>(input[1]);
        return true;
    }
	char *end;
	value = strtod(input.c_str(), &end);
	return (*end == '\0' || *end == 'f'); // Ensure entire input was valid
}

// Filter type
static int typeFilter(double value, const string &input) {
	if (input.length() == 3 && input[0] == '\'' && input[2] == '\'') // Single char
		return 0;
	if (value >= INT_MIN && value <= INT_MAX && input.find('.') == string::npos) // Integer
		return 1;
	if (input.find('f') != string::npos) // Float
		return 2;
	return 3; // Double
}

// Print char
static void printChar(double value, int type) {
    std::cout << "char: ";
    if (type == -1 || value < CHAR_MIN || value > CHAR_MAX) {
        std::cout << "Impossible" << std::endl;
    } else if (!std::isprint(static_cast<char>(value))) {
        std::cout << "Non displayable" << std::endl;
    } else {
        std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
    }
}

// Print int
static void printInt(double value, int type) {
	std::cout << "int: ";
	if (type == -1 || value < INT_MIN || value > INT_MAX) {
		std::cout << "Impossible" << std::endl;
	} else {
		std::cout << static_cast<int>(value) << std::endl;
	}
}

// Print float
static void printFloat(double value, int type) {
	std::cout << "float: ";
	if (type == -1 || value < -FLT_MAX || value > FLT_MAX) {
		std::cout << "Impossible" << std::endl;
	} else {
		std::cout << std::fixed << std::setprecision(1) << std::showpoint << static_cast<float>(value) << "f" << std::endl;
	}
}

// Print double
static void printDouble(double value, int type) {
	std::cout << "double: ";
	if (type == -1) {
		std::cout << "Impossible" << std::endl;
	} else {
		std::cout << std::fixed << std::setprecision(1) << std::showpoint << value << std::endl;
	}
}

// Helper function to check and adapt the behavior accordingly
static bool isPseudoLiteral(const std::string &input) {
    return input == "nan" || input == "nanf" || 
           input == "+inf" || input == "-inf" ||
           input == "+inff" || input == "-inff";
}

// Specifically handles the respective cases
static void handlePseudoLiteral(const std::string &input) {
    // Print common impossible cases
    std::cout << "char: Impossible" << std::endl;
    std::cout << "int: Impossible" << std::endl;

    // Check and handle the pseudo-literals
    if (input == "nan" || input == "nanf") {
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    } else if (input == "+inf" || input == "+inff") {
        std::cout << "float: +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;
    } else if (input == "-inf" || input == "-inff") {
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
    } else {
        // Handle unrecognized input
        std::cout << "Unrecognized pseudo-literal: " << input << std::endl;
    }
}

// static void handlePseudoLiteral(const std::string &input) {
//     std::cout << "char: Impossible" << std::endl;
//     std::cout << "int: Impossible" << std::endl;

//     if (input == "nan" || input == "nanf") {
//         std::cout << "float: nanf" << std::endl;
//         std::cout << "double: nan" << std::endl;
//     } else if (input == "+inf" || input == "+inff") {
//         std::cout << "float: +inff" << std::endl;
//         std::cout << "double: +inf" << std::endl;
//     } else if (input == "-inf" || input == "-inff") {
//         std::cout << "float: -inff" << std::endl;
//         std::cout << "double: -inf" << std::endl;
//     }
// }


// Main convert function
void Converter::convert(const string &input) {
    if (isPseudoLiteral(input)) {
        handlePseudoLiteral(input);
        return ;
    }
	double value;
	if (!isValidDouble(input, value)) {
		std::cout << "Invalid input" << std::endl;
		return;
	}
	int type = typeFilter(value, input);
	printChar(value, type);
	printInt(value, type);
	printFloat(value, type);
	printDouble(value, type);
}
