/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:56:47 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/11/19 10:12:27 by mcatalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

using std::string;

void formConstructor(string name, unsigned int gradeToSign, unsigned int gradeToExecute)
{
	try {
		Form form = Form(name, gradeToSign, gradeToExecute);
		std::cout << form << std::endl;
	}
	catch (std::exception &e) {
		std::cout << RED << "\tcatch: form constructor error. " << e.what() << RESET << std::endl;
	}
}

void formConstructorCorrectGrade()
{
	std::cout << std::endl << CYAN << "----- Test Form constructor with correct grade ----- " << RESET << std::endl;
	formConstructor("Marc", 120, 125);
}

void formConstructorOutOfRange()
{
	std::cout << std::endl << CYAN << "----- Test form constructor out of range ----- " << RESET << std::endl;
	std::cout << MAGENTA << "Grade too high" << RESET << std::endl;
	formConstructor("Marc", 0, 130);
	formConstructor("Marc", 130, 0);
	formConstructor("Marc", 200, 0);

	std::cout << std::endl << MAGENTA << "Grade too low" << RESET << std::endl;
	formConstructor("Marc", 130, 200);
	formConstructor("Marc", 200, 130);
}

void testBeSignedFunction()
{
	std::cout << std::endl << CYAN << "----- Test be Signed Function ----- " << RESET << std::endl;

	std::cout << std::endl << MAGENTA << "Try to sign with too low grade" << RESET << std::endl;
	try {
		Bureaucrat Marc("Marc", 65);
		Form form1("form1", 20, 50);
		form1.beSigned(Marc);
	}
	catch (std::exception &e) {
		std::cout << RED << "\tcatch: " << e.what() << RESET << std::endl;
	}
	std::cout << std::endl << MAGENTA << "Try to sign with correct grade" << RESET << std::endl;
	try {
		Bureaucrat Marc("Marc", 21);
		Form form1("form1", 45, 50);
		form1.beSigned(Marc);
		std::cout << std::endl << MAGENTA << "Try to sign when Form is already signed" << RESET << std::endl;
		Marc.signForm(form1);
	}
	catch (std::exception &e) {
		std::cout << RED << "\tcatch: " << e.what() << RESET << std::endl;
	}
	std::cout << std::endl << MAGENTA << "Try to sign form with correct grade" << RESET << std::endl;
	try {
		Bureaucrat Marc("Marc", 21);
		Form form2("form2", 56, 120);
		Marc.signForm(form2);
		std::cout << GREEN << form2 << RESET << std::endl;

	}
	catch (std::exception &e) {
		std::cout << RED << "\tcatch: " << e.what() << RESET << std::endl;
	}
}

int main()
{
	formConstructorCorrectGrade();
	formConstructorOutOfRange();
	testBeSignedFunction();
	return (0);
}
