/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 10:23:47 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/11/04 19:45:00 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

using std::string;

// Default constructor
ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", MIN_GRADE_SIGN_SC, MIN_GRADE_EXECUTE_SC), _target("undefinedTarget") {}

// Constructor with target
ShrubberyCreationForm::ShrubberyCreationForm(const string &target) : AForm("ShrubberyCreationForm", MIN_GRADE_SIGN_SC, MIN_GRADE_EXECUTE_SC), _target(target) {}

// copy constructor
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) { *this = src; }

// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm() {}

// operator "="
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src) {
	if (this != &src) {
		this->setIsSigned(src.getIsSigned());
		this->setGradeToSign(src.getGradeToSign());
		this->setGradeToExecute(src.getGradeToExecute());
	}
	return (*this);
}

// GETTERS
string ShrubberyCreationForm::getTarget() const { return (_target); }

// FUNCTIONS
// This function will create a file with trees
void addTreeFile(std::ofstream &outfile) {

	outfile << "		            .....\n"
			   "		       ......().......\n"
			   "      ....().................\n"
			   "     ..........................\n"
			   "   .......................()....\n"
			   "  ...............................\n"
			   "......()........................\n"
			   " ...................()......\n"
			   "      ...................\n"
			   "             |||\n"
			   "             |||\n"
			   "             |||\n"
			   "       ---------------\n"
			<< std::endl;
}

// This function will execute the form and create the trees
void ShrubberyCreationForm::executeConcreteForm() const {
	std::ofstream outfile((_target + "_shrubbery").c_str());
	if (!outfile.is_open()) {
		std::cout << "File has an error" << std::endl;
		return;
	}
	std::cout << GREEN << "Creating trees..." << RESET << std::endl;
	addTreeFile(outfile);
}

AForm *ShrubberyCreationForm::clone() {
	AForm *clone = new ShrubberyCreationForm(*this);
	return (clone);
}

// operador "<<"
std::ostream &operator<<(std::ostream &out, const ShrubberyCreationForm &SCform) {
	out << YELLOW << "[" << SCform.getTarget() << "] Shrubbery Creation Form | Grade to sign: "
		<< SCform.getGradeToSign() << " | Grade to execute: " << SCform.getGradeToExecute();
	if (SCform.getIsSigned())
		out << " | Form is Signed." << std::endl;
	else
		out << " | form is not signed." << std::endl;
	return (out);
}
