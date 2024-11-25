/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 10:22:37 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/11/02 17:32:49 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

using std::string;

// Default constructor
PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", MIN_GRADE_SIGN_PP, MIN_GRADE_EXECUTE_PP), _target("undefinedTarget") {}

// Constructor wih target
PresidentialPardonForm::PresidentialPardonForm(const string &target) : AForm("PresidentialPardonForm", MIN_GRADE_SIGN_PP, MIN_GRADE_EXECUTE_PP), _target(target) {}

// copy constructor
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) { *this = src; }

// Destructor
PresidentialPardonForm::~PresidentialPardonForm() {}

// operator "="
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &src) {
	if (this != &src) {
		this->setIsSigned(src.getIsSigned());
		this->setGradeToSign(src.getGradeToSign());
		this->setGradeToExecute(src.getGradeToExecute());
	}
	return (*this);
}

// GETTERS
string PresidentialPardonForm::getTarget() const { return (_target); }

// FUNCTIONS
void PresidentialPardonForm::executeConcreteForm() const {
	std::cout << GREEN << getTarget() + " has been pardoned by Zaphod Beeblebrox." << RESET << std::endl;
}

// operator "<<"
// This operator will print the form information in the following format:
// [target] Presidential Pardon Form | Grade to sign: [gradeToSign] | Grade to execute: [gradeToExecute] | [form is signed or not]
std::ostream &operator<<(std::ostream &out, const PresidentialPardonForm &SCform) {
	out << YELLOW << "[" << SCform.getTarget() << "] Presidential Pardon Form | Grade to sign: "
		<< SCform.getGradeToSign() << " | Grade to execute: " << SCform.getGradeToExecute();
	if (SCform.getIsSigned())
		out << " | Form is Signed." << RESET << std::endl;
	else
		out << " | form is not signed." << RESET << std::endl;
	return (out);
}

