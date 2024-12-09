/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 11:12:39 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/12/09 11:14:19 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

ScalarConverter::ScalarConverter(void)
{
}

ScalarConverter::ScalarConverter(ScalarConverter const & source) { *this = source; }

ScalarConverter & ScalarConverter::operator=(ScalarConverter const & source) {
	if (this != &source)
		return (*this);
	return (*this);    
}

ScalarConverter::~ScalarConverter(void) {}

// Functions
int ScalarConverter::detectType(std::string str) {
	std::string	strCopy = str;
	
	if ((str[0] == '+' || str[0] == '-') && str[1])
		strCopy = str.substr(1, str.length() - 1);
	if (strCopy.substr(0,3) == "inf" || strCopy.substr(0,3) == "nan" || isdigit(strCopy.at(0))) {
		if (strCopy.at(strCopy.length() - 1) == 'f' && strCopy != "inf" && strCopy != "nan")
			return IS_FLOAT;
		if (strCopy.find('.') != std::string::npos || strCopy == "inf" || strCopy == "nan")
			return IS_DOUBLE;
		return IS_INT;
	}
	if (isprint(str[0]) && str.length() == 1)
		return IS_CHAR;
	return IS_ERROR;	
}

void	ScalarConverter::printCastFromChar(std::string str) {
	std::cout << "char: " << "'" << str[0] << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(str[0]) << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << static_cast<float>(str[0]) << 'f' << std::endl;
	std::cout << "double: " << static_cast<double>(str[0]) << std::endl;
}

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

void	ScalarConverter::printCastFromFloat(std::string str) {
	float	value;

	value = static_cast<float>(std::atof(str.c_str()));
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
	std::cout << "float: " << value << 'f' << std::endl;
	std::cout << "double: " << static_cast<double>(std::atof(str.c_str())) << std::endl;
}

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

const char* ScalarConverter::InvalidFormat::what() const throw() { return ("Error - Invalid input format."); }
