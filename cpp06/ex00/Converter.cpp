/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:53:47 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/12/10 14:57:39 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

// Default constructor
ScalarConverter::ScalarConverter(void) {}

// Copy constructor
ScalarConverter::ScalarConverter(ScalarConverter const & source) { *this = source; }

// Operator overload
ScalarConverter & ScalarConverter::operator=(ScalarConverter const & source) {
	if (this != &source)
		return (*this);
	return (*this);    
}

// Destructor
ScalarConverter::~ScalarConverter(void) {}

// Functions
/*
	This function detects the type of the input string. Checks if there is any
	'+' or '-' sign at the beginning of the string and removes it. Then checks
	if the input is a submod
*/
int ScalarConverter::detectType(std::string str) {
	std::string strCopy = str;

    // Remove leading '+' or '-' if present
    if ((str[0] == '+' || str[0] == '-') && str.length() > 1)
        strCopy = str.substr(1);

    // Check for special floating-point literals
    if (strCopy == "inf" || strCopy == "nan")
        return IS_DOUBLE;
    if (strCopy == "inff" || strCopy == "nanf")
        return IS_FLOAT;

    // Check if it is a valid digit or decimal point
    if (isdigit(strCopy[0]) || strCopy[0] == '.') {
        if (strCopy.find('.') != std::string::npos) {
            // Check for float literals (ends with 'f')
            if (strCopy.length() > 1 && strCopy[strCopy.length() - 1] == 'f')
                return IS_FLOAT;
            return IS_DOUBLE;
        }
        return IS_INT;
    }

    // Check if it's a single printable character
    if (isprint(str[0]) && str.length() == 1)
        return IS_CHAR;

    return IS_ERROR;	
}

/*
	This function print the cast from a char type input.
	We use fixed and setprecision to print the float with one decimal
	and the char is printed between single quotes.
*/

void	ScalarConverter::printCastFromChar(std::string str) {
	std::cout << "char: " << "'" << str[0] << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(str[0]) << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << static_cast<float>(str[0]) << 'f' << std::endl;
	std::cout << "double: " << static_cast<double>(str[0]) << std::endl;
}

/*
	This function print the cast from an int type input.
	We check if the value is between 32 and 127 to print printable char.
	We check if the value is between 0 and UCHAR_MAX to print non displayable
	char (except for the chars in 32 to 127).
*/
void	ScalarConverter::printCastFromInt(std::string str) {
	long	value;

	value = std::strtol(str.c_str(), NULL, 10);
	if (value >= 32 && value <= 127)
		std::cout << "char: " << "'" << static_cast<char>(value) << "'" << std::endl;
	else if ((value >= 0 && value < 32) || (value > 127 && value <= UCHAR_MAX))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: impossible" << std::endl;
	if (value > INT_MAX || value < INT_MIN)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " <<  value << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << static_cast<float>(value) << 'f' << std::endl;	
	std::cout << "double: " << static_cast<double>(value) << std::endl;
}

/*
	This function print the cast from a float type input.
	We check if the value is inf or nan, if it is, we print impossible for char and int.
	We check if the value is between 0 and UCHAR_MAX to print non displayable
	char (except for the chars in 32 to 127).
*/
void	ScalarConverter::printCastFromFloat(std::string str) {
	float	value;

	value = static_cast<float>(std::atof(str.c_str()));
	if (str.find("inf") != std::string::npos || str.find("nan") != std::string::npos || value < 0 || value >= UCHAR_MAX + 1)
		std::cout << "char: impossible" << std::endl;
	else if ((value >= 0 && value < 32) || (value > 127 && value < UCHAR_MAX + 1))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: " << "'" << static_cast<char>(value) << "'" << std::endl;
	if (str.find("inf") != std::string::npos || str.find("nan") != std::string::npos || value < static_cast<float>(INT_MIN) || value > static_cast<float>(INT_MAX)) 
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " <<  static_cast<int>(value) << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << value << 'f' << std::endl;
	std::cout << "double: " << static_cast<double>(std::atof(str.c_str())) << std::endl;
}

/*
	This function print the cast from a double type input.
	We check if there is any inf or nan, if it is, we print impossible for char and int.
*/
void	ScalarConverter::printCastFromDouble(std::string str) {
	double	value;

	value = std::atof(str.c_str());
	if (str.find("inf") != std::string::npos || str.find("nan") != std::string::npos || value < 0 || value >= UCHAR_MAX + 1)
		std::cout << "char: impossible" << std::endl;
	else if ((value >= 0 && value < 32) || (value > 127 && value < UCHAR_MAX + 1))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: " << "'" << static_cast<char>(value) << "'" << std::endl;
	if (str.find("inf") != std::string::npos || str.find("nan") != std::string::npos || value < INT_MIN || value > INT_MAX)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " <<  static_cast<int>(value) << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << static_cast<float>(value) << 'f' << std::endl;
	std::cout << "double: " << value << std::endl;
}

/*
	This function is a switch case that using detectType function selects the correct
	function to print the cast from the input string. If the input string is not a
	valid type, it throws an exception.
*/
void ScalarConverter::convert(std::string const str) {

	switch (detectType(str)) {
		case 0:
			printCastFromChar(str);
			break;
		case 1:
			printCastFromInt(str);
			break;
		case 2:
			printCastFromFloat(str);
			break;
		case 3:
			printCastFromDouble(str);
			break;
		case 4:
			throw ScalarConverter::InvalidFormat();
	}
}

/*
	Exception class print the error message when the input string is not a valid type.
*/
const char* ScalarConverter::InvalidFormat::what() const throw() { return ("Error - Invalid input format."); }
