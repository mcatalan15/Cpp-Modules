/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 19:09:42 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/11/06 13:06:58 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

using std::string;

// Default constructor
Intern::Intern() {}

// Copy constructor
Intern::Intern(const Intern &src) { *this = src; }

// Destructor
Intern::~Intern() {}

// Operator "="
Intern &Intern::operator=(const Intern &src) {
	(void)src;
	return (*this);
}

// FUNCTIONS
/*
	This function creates a  form depending on the formName and target. Uses the clone method from the
	form to create a new form and through a loop, it compares the formName with the names of the forms
	that can be created. Checks if the formName is equal to the name of the form, if it is, it creates
	the form and returns it. If it is not, it returns NULL.
*/
AForm *Intern::makeForm(const std::string &formName, const std::string &target) const
{
	ShrubberyCreationForm SCForm = ShrubberyCreationForm(target);
	RobotomyRequestForm RRForm = RobotomyRequestForm(target);
	PresidentialPardonForm PPForm = PresidentialPardonForm(target);
	AForm *forms[] = {&SCForm, &RRForm, &PPForm};

	for (int i = 0; i < 3; i++)
	{
		if (!formName.compare(forms[i]->getName()))
		{
			std::cout << "Intern creates " << formName << std::endl;
			return (forms[i]->clone());
		}
	}
	std::cout << RED << "Form doesn't exist." << RESET << std::endl;
	return (NULL);
}
