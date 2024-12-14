<<<<<<< Updated upstream
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

=======
>>>>>>> Stashed changes
#include "Base.hpp"
#include <cstdlib>
#include <ctime>
/*
	This function generates a randum number between 1 and 3.
	Then it creates a new instance of A, B or C depending on the random number.
*/
<<<<<<< Updated upstream
Base *generate()
{

	srand(time(NULL));
	int randomNumber = rand() % 3 + 1;
	Base *base = NULL;
	if (randomNumber == 1)
		base = new A;
	if (randomNumber == 2)
		base = new B;
	if (randomNumber == 3)
		base = new C;
	return (base);
=======
Base* generate() {
    
    srand(time(NULL));
    int randomNumber = rand() % 3 + 1;
    Base* base = NULL;
    if (randomNumber == 1)
        base = new A;
    if (randomNumber == 2)
        base = new B;
    if (randomNumber == 3)
        base = new C;
    return (base);
>>>>>>> Stashed changes
}
/*
	This function identifies the class from a pointer.
	It uses dynamic_cast to check if the pointer is an instance of A, B or C.
*/
<<<<<<< Updated upstream
void identify(Base *p)
{
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
	// delete a;
	// delete b;
	// delete c;
=======
void    identify(Base* p) {
    std::cout << "Identify class from pointer" << std::endl;
    A* a = dynamic_cast<A*>(p);
    B* b = dynamic_cast<B*>(p);
    C* c = dynamic_cast<C*>(p);
    if (a)
        std::cout << "Class A" << std::endl;
    else if (b)
        std::cout << "Class B" << std::endl;
    else if (c)
        std::cout << "Class C" << std::endl;
    // delete a;
    // delete b;
    // delete c;
>>>>>>> Stashed changes
}
/*
	This function identifies the class from a reference.
	It uses dynamic_cast to check if the reference is an instance of A, B or C.
*/
<<<<<<< Updated upstream
void identify(Base &p)
{
	std::cout << "Identify class from reference" << std::endl;
	if (dynamic_cast<A *>(&p))
		std::cout << "Class A" << std::endl;
	else if (dynamic_cast<B *>(&p))
		std::cout << "Class B" << std::endl;
	if (dynamic_cast<C *>(&p))
		std::cout << "Class C" << std::endl;
=======
void    identify(Base & p) {
    std::cout << "Identify class from reference" << std::endl;
    if (dynamic_cast<A*>(&p))
        std::cout << "Class A" << std::endl;
    else if (dynamic_cast<B*>(&p))
        std::cout << "Class B" << std::endl;
    if (dynamic_cast<C*>(&p))
        std::cout << "Class C" << std::endl;
>>>>>>> Stashed changes
}
/*
	Main function that generates a random class and identifies it.
*/
<<<<<<< Updated upstream
int main()
{
	Base *base = generate();
	identify(base);
	identify(*base);
	delete base;
	return (0);
=======
int main() {
    Base* base = generate();
    identify(base);
    identify(*base);
	delete base;
    return (0);
>>>>>>> Stashed changes
}