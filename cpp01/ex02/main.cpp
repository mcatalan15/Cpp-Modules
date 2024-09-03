/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 08:02:46 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/09/03 19:04:52 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

/*
	*What is a pointer to a str?
	-stringPTR: Pointer to a string
	It is a variable that holds the memory address of a string variable.
	
	*What is a reference to a str?
	-stringREF: Reference to a string
	
	Both are pointing to the same string variable.
	They are different ways to access the same variable.
	The main diference is that a reference is an alias to the variable and a
	pointer is a variable that holds the memory address of the variable.
*/

int	main()	{

	std::string	str = "HI THIS IS BRIAN";

	std::string	*stringPTR = &str;

	std::string	&stringREF = str;

	std::cout << "memory address of the string variable: " << &str << std::endl;
	std::cout << "memory address held by stringPTR: " << stringPTR << std::endl;
	std::cout << "memory address held by stringREF: " << &stringREF << std::endl;
	std::cout << std::endl;
	std::cout << "value of the string variable: " << str << std::endl;
	std::cout << "value pointed to by stringPTR: " << *stringPTR << std::endl;
	std::cout << "value pointed to by stringREF: " << stringREF << std::endl;

	return 0;
}

