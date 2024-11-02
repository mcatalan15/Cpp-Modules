/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 10:23:52 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/11/02 17:40:47 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

using std::string;

// Default constructor
RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", MIN_GRADE_SIGN_RR, MIN_GRADE_EXECUTE_RR), _target("undefinedTarget") {}

// Constructor with target
RobotomyRequestForm::RobotomyRequestForm(const string &target) : AForm("RobotomyRequestForm", MIN_GRADE_SIGN_RR, MIN_GRADE_EXECUTE_RR), _target(target) {}

// copy constructor
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) { *this = src; }

// Destructor
RobotomyRequestForm::~RobotomyRequestForm() {}

// operator "="
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src) {
	if (this != &src) {
		this->setIsSigned(src.getIsSigned());
		this->setGradeToSign(src.getGradeToSign());
		this->setGradeToExecute(src.getGradeToExecute());
	}
	return (*this);
}

// GETTERS
string RobotomyRequestForm::getTarget() const { return (_target); }

// FUNCTIONS
// This function will execute the form and make the robotomy
void RobotomyRequestForm::executeConcreteForm() const {
	std::cout << GREEN << "trrrr trrrr\nbrrr brrr" << std::endl;
	std::cout << getTarget() + " has been robotomized successfully 50% of the time." << RESET << std::endl;
}

// operador "<<"
std::ostream &operator<<(std::ostream &out, const RobotomyRequestForm &SCform) {
	out << YELLOW << "[" << SCform.getTarget() << "] Robotomy request Form | Grade to sign: "
		<< SCform.getGradeToSign() << " | Grade to execute: " << SCform.getGradeToExecute();
	if (SCform.getIsSigned())
		out << " | Form is Signed." << std::endl;
	else
		out << " | form is not signed." << std::endl;
	return (out);
}
