/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 19:09:42 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/11/04 19:37:24 by mcatalan@st      ###   ########.fr       */
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
AForm *Intern::makeForm(const std::string &formName, const std::string &target) const
{
	ShrubberyCreationForm SCForm = ShrubberyCreationForm(target);
	RobotomyRequestForm RRForm = RobotomyRequestForm(target);
	PresidentialPardonForm PPForm = PresidentialPardonForm(target);
	AForm *forms[] = {&SCForm, &RRForm, &PPForm};

	for (int i = 0; i < 3; i++)
	{
		if (formName.compare(forms[i]->getName()))
		{
			std::cout << "Intern creates " << formName << std::endl;
			return (forms[i]->clone());
		}
	}
	std::cout << RED << "Form doesn't exist." << RESET << std::endl;
	return (NULL);
}
