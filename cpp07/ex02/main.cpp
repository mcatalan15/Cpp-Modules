/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 20:16:36 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/12/13 20:16:37 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp" 
#include "Array.tpp" 
#include <sstream>

/*
	This main is used to test the Array class.
	Creates two arrays, one of integers and one of characters.
	Assigns values to the arrays and prints them.
	This way we can see that the class works correctly.
*/
int main() {
	Array<int> arr1(5);
	Array<char> arr2(5);

	for(unsigned int i = 0; i < arr2.size(); i++)
		arr2[i] = i + 'a';
	for (unsigned int i = 0; i < arr1.size(); i++)
		arr1[i] = i * 2;

	for (unsigned int i = 0; i < arr1.size(); i++)
		std::cout << arr1[i] << " ";
	std::cout << std::endl;
	for (unsigned int i = 0; i < arr2.size(); i++)
		std::cout << arr2[i] << " ";
	std::cout << std::endl;
}
