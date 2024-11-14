/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 12:54:18 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/11/13 11:01:21 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

using std::string;

// Default constructor
Converter::Converter() {}

// Copy constructor
Converter::Converter(const Converter &src) { *this = src; }

// Destructor
Converter::~Converter() {}

// Assignment operator "="
Converter &Converter::operator=(const Converter &src) { (void)src; return (*this); }

//Utils
// Strlen function. Returns the length of a string
static int ft_strlen(const string &str) {
    int i = 0;
    while (str[i] != '\0')
        i++;
    return (i);
}

// Isdigit function. Returns true if the character is a digit
static bool ft_isdigit(char c) {
    if (c >= 0 + '0' && c <= 9 + '0')
        return (true);
    else
        return (false);
}

//Functions
static bool isChar(const string &input) {
    if (ft_strlen(input) != 3)
        return (false);
    if (input[0] != '\'' || input[2] != '\'' || input[1] < 32 || input[1] > 126)
        return (false);
    return (true);
}

static bool isInt(const string &input) {
    int i = 0;
    if (input[0] == '-')
        i++;
    while (i < ft_strlen(input)) {
        if (!ft_isdigit(input[i]))
            return (false);
        i++;
    }
    try {
        atoi(input.c_str()); 
    } catch (const std::invalid_argument& e) { return (false); }
    return (true);
}

static bool isFloat(const string &input) {
    if (input == "nanf" || input == "-inff" || input == "+inff")
        return (true);
    if ((input[0] != '-' && !ft_isdigit(input[0])) || input[ft_strlen(input) - 1] != 'f')
        return (false);
    int i = 0;
    bool point = false;
    if (input[0] == '-')
        i++;
    while (i < ft_strlen(input) - 1) {
        if (!ft_isdigit(input[i]) && input[i] != '.')
            return (false);
        if (input[i] == '.' && point)
            return (false);
        else if (input[i] == '.')
                point = true;
        i++;
    }
    try {
        strtod(input); 
    } catch (const std::invalid_argument& e) { return (false); }
    return (true);
}

static bool isDouble(const string &input) {
    if (input == "nan" || input == "-inf" || input == "+inf")
        return (true);
    if ((input[0] != '-' && !ft_isdigit(input[0])))
        return (false);
    int i = 0;
    bool point = false;
    if (input[0] == '-')
        i++;
    while (i < ft_strlen(input)) {
        if (!ft_isdigit(input[i]) && input[i] != '.')
            return (false);
        if (input[i] == '.' && point)
            return (false);
        else if (input[i] == '.')
                point = true;
        i++;
    }
    try {
        strtod(input); 
    } catch (const std::invalid_argument& e) { return (false); }
    return (true);
}

// filter function
static int typeFilter(const string &input) {
    if (isChar(input))
        return (0);
    if (isInt(input))
        return (1);
    if (isFloat(input))
        return (2);
    if (isDouble(input))
        return (3);
	return (-1);
}

//Print functions
static void printChar(const string &input, int type) {
    std::cout << "char: ";
    if (type == -1) {
        std::cout << "Impossible" << std::endl;
        return ;
    }
    if (type == 0) { std::cout << input << std::endl; return ; }
    try {
        int nbInt = std::stoi(input);
        if (nbInt < 32 || nbInt > 126)
            std::cout << "Non displayable" << std::endl;
        else
            std::cout << "\'" << static_cast<char>(nbInt) << "\'" << std::endl;
    }
    catch (const std::invalid_argument &e) { std::cout << "Impossible" << std::endl; }
}


static void printInt(const string &input, int type) {
    std::cout << "int: ";
    if (type == -1) {
        std::cout << "Impossible" << std::endl;
        return ;
    }
    try {
        int nbInt = std::stoi(input);
        int castInt = static_cast<int>(nbInt);
        std::cout << castInt << std::endl;
    } catch(const std::invalid_argument &e) { std::cout << "Impossible" << std::endl; }
}

static void printFloat(const string &input, int type) {
    std::cout << "float: ";
    if (type == -1) {
        std::cout << "Impossible" << std::endl;
        return ;
    }
    try {
        float nbFloat = std::stof(input);
        if (type == 1 || (nbFloat - static_cast<int>(nbFloat) == 0))
            std::cout << static_cast<float>(nbFloat) << ".0f" << std::endl;
        else
            std::cout << static_cast<float>(nbFloat) << "f" << std::endl;
    } catch(const std::invalid_argument &e) { std::cout << "Impossible" << std::endl; }
}

static void printDouble(const string &input, int type) {
    std::cout << "double: ";
    if (type == -1) {
        std::cout << "Impossible" << std::endl;
        return ;
    }
    if (input == "+inff" || input == "+inf")
        std::cout << "inf" << std::endl;
    else if(input == "+nanf" || input == "nan")
        std::cout << "nan" << std::endl;
    else if (input == "-inff" || input == "-inf")
        std::cout << "-inf" << std::endl;
    else {
        try {
            double nbDouble = std::stod(input);
            if (type == 1 || (nbDouble - static_cast<int>(nbDouble) == 0))
                std::cout << static_cast<double>(nbDouble) << ".0" << std::endl;
            else
                std::cout << static_cast<double>(nbDouble) << std::endl;
        } catch(const std::invalid_argument &e) { std::cout << "Impossible" << std::endl; }
    }
}

void  Converter::convert(const string &input) {
    int type = typeFilter(input);
    printChar(input, type);
    printInt(input, type);
    printFloat(input, type);
    printDouble(input, type);
}

