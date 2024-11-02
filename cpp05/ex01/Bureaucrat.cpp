/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:56:36 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/10/24 19:27:13 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

using std::string;

// Default constructor
Bureaucrat::Bureaucrat() : _name("uname"), _grade(MAX_GRADE) {}

// Constructor
Bureaucrat::Bureaucrat(const string &name, const unsigned int grade) : _name(name) {
	if (grade < MIN_GRADE)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > MAX_GRADE)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade = grade;
}

// Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat &src) { *this = src; }

// Destructor
Bureaucrat::~Bureaucrat() {}

// Assignment Operator '='
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src) {
	if (this != &src)
		this->_grade = src.getGrade();
	return (*this);
}

// Getters
string Bureaucrat::getName() const { return (_name); }
unsigned int Bureaucrat::getGrade() const { return (_grade); }

// Functions
// Increment grade by 1
void Bureaucrat::incrementGrade() {
	if (this->_grade - 1 < MIN_GRADE)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade--;
}

// Increment grade by custom value
void Bureaucrat::incrementGrade(unsigned int increment) {
	if (this->_grade < MIN_GRADE + increment)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade -= increment;
}

// Decrement grade by 1
void Bureaucrat::decrementGrade() {
	if (this->_grade + 1 > MAX_GRADE)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade++;
}

// Decrement grade by custom value
void Bureaucrat::decrementGrade(unsigned int decrement) {
	if (this->_grade + decrement > MAX_GRADE)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade += decrement;
}

// Method for a Bureaucrat to sign a Form
void Bureaucrat::signForm(Form &form) {
	if (form.getIsSigned())
		throw Form::FormIsSignedException(""); // Exception: Form is already signed
	else
	{
		try {
			form.beSigned(*this); // Try to sign the form
			std::cout << GREEN << form.getName() << " is signed by " << this->_name << RESET << std::endl; // Success message
		}
		catch (std::exception &e) { // Catch exception and message
			std::cout << this->_name << " could not sign " << form.getName() << " because " << e.what() << std::endl;
		}
	}
}

// Exceptions methods
const char *Bureaucrat::GradeTooHighException::what() const throw() { return ("Grade too high"); }
const char *Bureaucrat::GradeTooLowException::what() const throw() { return ("Grade too low"); }

// Overload operator '<<' to print Bureaucrat info
std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat) {
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return (out);
}
