/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:56:47 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/11/05 11:54:03 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

/*
	Function to test the ShrubberyCreationForm.
	This class is a child of AForm.
*/
void	testSchrubbery() {
	std::cout << "\n----- Shrubbery Creation Form Test-----\n" << std::endl;
	Bureaucrat marc("Marc", 137);
	ShrubberyCreationForm shrubbery("Home");
	try {
		shrubbery.execute(marc);
	}
	catch (const std::exception &e) {
		std::cerr << "\tcatch: " << e.what() << std::endl;
	}

	try {
		shrubbery.beSigned(marc);
		shrubbery.execute(marc);
	}
	catch (const std::exception &e) {
		std::cerr << "\tcatch: " << e.what() << std::endl;
	}
}

/*
	Function to test the RobotomyRequestForm.
	This class is a child of AForm.
*/
void testRobotomy() {
	std::cout << "\n----- Robotomy Request Form Test-----\n" << std::endl;
	Bureaucrat pepe("Pepe", 45);
	RobotomyRequestForm robotomy("home");
	try {
		robotomy.execute(pepe);
	}
	catch (const std::exception &e) {
		std::cerr << "\tcatch: " << e.what() << std::endl;
	}

	try {
		robotomy.beSigned(pepe);
		robotomy.execute(pepe);
		robotomy.execute(pepe);

	}
	catch (const std::exception &e) {
		std::cerr << "\tcatch: " << e.what() << std::endl;
	}
}

/*
	Function to test the PresidentialPardonForm.
	This class is a child of AForm.
*/
void testPresidential() {
	std::cout << "\n----- Presidential Pardon Form Test-----\n" << std::endl;
	Bureaucrat marc("Marc", 5);
	PresidentialPardonForm pardon("pedro");
	try {
		pardon.beSigned(marc);
		pardon.execute(marc);
	}
	catch (const std::exception &e) {
		std::cerr << "\tcatch: " << e.what() << std::endl;
	}
}

// Function to test the Bureaucrat class.
void testBureaucrat() {
	std::cout << "\n----- Bureaucrat Test-----\n" << std::endl;
	Bureaucrat marc("Marc", 137);
	ShrubberyCreationForm shrubbery("Home");
	RobotomyRequestForm robotomy("home");
	try {
		marc.signForm(shrubbery);
		std::cout << GREEN << shrubbery.getName() << " is signed by " << marc.getName() << RESET << std::endl;
	}
	catch (const std::exception &e) {
		std::cerr << marc.getName() << " could not sign " << shrubbery.getName() << " because " << e.what() << std::endl;
	}

	try {
		marc.signForm(robotomy);
	}
	catch (const std::exception &e) {
		std::cerr << marc.getName() << " could not sign " << robotomy.getName() << " because " << e.what() << std::endl;
	}

	try {
		marc.executeForm(robotomy);
	}
	catch (const std::exception &e) {
		std::cerr << "\texecution catch: " << e.what() << std::endl;
	}
}

// Function to test the canonical form.
void testCanonical() {
	std::cout << "\n----- Test canonical form -----\n" << std::endl;
	ShrubberyCreationForm shrubbery("Home");
	RobotomyRequestForm robotomy("News");
	PresidentialPardonForm pardon("Work");

	std::cout << shrubbery << std::endl;
	std::cout << robotomy << std::endl;
	std::cout << pardon << std::endl;
}

//	Main function
int main() {
	testSchrubbery();
	testRobotomy();	
	testPresidential();
	testBureaucrat();
	testCanonical();

	return 0;
}
