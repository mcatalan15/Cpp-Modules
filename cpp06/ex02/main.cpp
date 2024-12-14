/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 12:11:14 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/12/13 12:11:15 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <cstdlib>
#include <ctime>

/*
	This function generates a random number between 1 and 3.
	Then it creates a new instance of A, B or C depending on the random number.
*/
Base *generate() {
	int randomNumber = rand() % 3;
	Base *base = NULL;
	if (randomNumber == 1)
		base = new A;
	if (randomNumber == 2)
		base = new B;
	if (randomNumber == 3)
		base = new C;
	return (base);
}

/*
	This function identifies the class from a pointer.
	It uses dynamic_cast to check if the pointer is an instance of A, B or C.
*/
void identify(Base *p) {
	std::cout << "Identify class from pointer" << std::endl;
	A *a = dynamic_cast<A *>(p);
	B *b = dynamic_cast<B *>(p);
	C *c = dynamic_cast<C *>(p);
	if (a)
		std::cout << "Class A" << std::endl;
	else if (b)
		std::cout << "Class B" << std::endl;
	else if (c)
		std::cout << "Class C" << std::endl;
	else
		std::cout << "none" << std::endl;
}

/*
	This function identifies the class from a reference.
	It uses dynamic_cast to check if the reference is an instance of A, B or C.
*/
void identify(Base &p) {
	std::cout << "Identify class from reference" << std::endl;
	if (dynamic_cast<A *>(&p))
		std::cout << "Class A" << std::endl;
	else if (dynamic_cast<B *>(&p))
		std::cout << "Class B" << std::endl;
	else if (dynamic_cast<C *>(&p))
		std::cout << "Class C" << std::endl;		
}

/*
	Main function that generates a random class and identifies it.
*/
int main() {
	Base *base = generate();
	identify(base);
	identify(*base);
	delete base;
	return (0);
}
