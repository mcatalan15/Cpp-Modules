/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 20:18:31 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/12/13 20:21:59 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp" 

/*
	In this test we create a span of 5 numbers and try to find the shortest and longest span.
	We create a span of 5 numbers and add two numbers to it.
*/
void mandatoryTest(){
	std::cout << std::endl << "----- Mandatory test ----- " << std::endl;
	Span sp = Span(5);
	try {
		sp.addNumber(-2147483648);
		sp.addNumber(10);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;	
	}
	catch(const std::runtime_error& e){
		std::cout << RED << "Error: " << e.what() << RESET << std:: endl;
	}
}

/*
	In this test we try to add more numbers than the span can hold.
*/
void spanIsFullTest(){
	std::cout << std::endl << "----- Full span test ----- " << std::endl;
	Span sp = Span(2);
	try {
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;	
	}
	catch(const std::runtime_error& e){
		std::cout << RED << "Error: " << e.what() << RESET << std:: endl;
	}
}

/*
	In this case we create a span of 5 numbers and add just one number.
	It throws an error because the span has less than 2 numbers.
*/
void notEnoughNumbers(){
	std::cout << std::endl << "----- Short span test ----- " << std::endl;
	Span sp = Span(5);
	try {
		sp.addNumber(6);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;	
	}
	catch(const std::runtime_error& e){
		std::cout << RED << "Error: " << e.what() << RESET << std:: endl;
	}
}

/*
	In this test we create a span of 10000 numbers and add random numbers to it.
	We then try to find the shortest and longest span.
*/
void randomFillSpanTest(){
	std::cout << std::endl << "----- Random Fill Span test ----- " << std::endl;
	Span sp = Span(10000);
	sp.addRangeNumbers();
	try {
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;	
	}
	catch(const std::runtime_error& e){
		std::cout << RED << "Error: " << e.what() << RESET << std:: endl;
	}
	std::cout << "Span size: " << sp.getSpan().size() << std::endl;
}

/*
	We run all the tests.
*/
int main() {
	mandatoryTest();
	spanIsFullTest();
	notEnoughNumbers();
	randomFillSpanTest();
	return (0);
}

