/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 20:15:42 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/12/13 20:15:43 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

/*
	This is a simple test to check if the easyfind function works.
	We create a list of integers and try to find a number in it.
	If the number is found, we print it.
	If the number is not found, we print an error message.
*/
int main() {
	int find = 3;

	std::list<int>	container;

	container.push_back(1);
	container.push_back(2);
	container.push_back(3);

	try {
		// easyfind(container, find);
		std::list<int>::const_iterator it = ::easyfind(container, find);
		std::cout << GREEN << "Found: " << *it << RESET << std::endl;
	} catch (std::exception &e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}
}
