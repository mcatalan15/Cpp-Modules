/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:56:36 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/11/02 17:30:43 by mcatalan@st      ###   ########.fr       */
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

// Operator '='
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src) {
	if (this != &src)
		this->_grade = src.getGrade();
	return (*this);
}

// Getters
string Bureaucrat::getName() const { return (_name); }

unsigned int Bureaucrat::getGrade() const { return (_grade); }

// FUNCTIONS
//Increment grade functions
// Increment w/o parameter
void	Bureaucrat::incrementGrade() {
	if (this->_grade - 1 < MIN_GRADE)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade--;
}
// Increment with parameter
void	Bureaucrat::incrementGrade(unsigned int increment) {
	if (this->_grade - increment < MIN_GRADE)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade -= increment;
}

// Decrement grade functions
// Decrement w/o parameter
void	Bureaucrat::decrementGrade() {
	if (this->_grade + 1 > MAX_GRADE)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade++;
}
// Decrement with parameter
void	Bureaucrat::decrementGrade(unsigned int decrement) {
	if (this->_grade + decrement > MAX_GRADE)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade += decrement;
}
// Function to sign a form if the form is not signed
void	Bureaucrat::signForm(AForm & form){
	if (form.getIsSigned()){
		throw AForm::FormIsSignedException("");
	}
	else {
		try {
			form.beSigned(*this);
			std::cout << GREEN << form.getName() << " is signed by " << this->_name << RESET << std::endl;  
		}
		catch (std::out_of_range & e) {
			std::cout << this->_name << " could not sign " << form.getName() << \
			" beacuse " << e.what() << std::endl;;

		}
	}
}
// Function to execute a form
void Bureaucrat::executeForm(const AForm &form)
{
	try {
		form.execute(*this);
		std::cout << this->_name << " executed " << form.getName() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "\texecution catch: " << e.what() << std::endl;
	}
}

// Exceptions with specific messages
const char	*Bureaucrat::GradeTooHighException::what () const throw () { return("Range too high"); }

const char	*Bureaucrat::GradeTooLowException::what () const throw () { return("Range too low"); }

// Operator "<<"
std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat) {
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return (out);
}
