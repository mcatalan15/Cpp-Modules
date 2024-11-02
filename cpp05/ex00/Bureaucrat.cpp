/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 10:34:05 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/10/24 19:27:37 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

using std::string;

// Default constructor
Bureaucrat::Bureaucrat() : _name("uname"), _grade(MAX_GRADE) {}

// Constructor
Bureaucrat::Bureaucrat(const string &name, const unsigned int grade) : _name(name) {
	if (grade < MIN_GRADE)
		throw Bureaucrat::GradeTooHighException(); // Grade too high
	else if (grade > MAX_GRADE)
		throw Bureaucrat::GradeTooLowException(); // Grade too low
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
		this->_grade = src.getGrade(); // Copy grade, name is const
	return (*this);
}

// Getters
string Bureaucrat::getName() const { return (_name); }

unsigned int Bureaucrat::getGrade() const { return (_grade); }

// Functions
// Increment grade by 1
void	Bureaucrat::incrementGrade() {
	if (this->_grade - 1 < MIN_GRADE)
		throw Bureaucrat::GradeTooHighException(); // Grade too high
	else
		this->_grade--;
}

// Increment grade by custom value
void	Bureaucrat::incrementGrade(unsigned int increment) {
	if (this->_grade < MIN_GRADE + increment)
		throw Bureaucrat::GradeTooHighException(); // Grade too high
	else
		this->_grade -= increment;
}

// Decrement grade by 1
void	Bureaucrat::decrementGrade() {
	if (this->_grade + 1 > MAX_GRADE)
		throw Bureaucrat::GradeTooLowException(); // Grade too low
	else
		this->_grade++;
}

// Decrement grade by custom value
void	Bureaucrat::decrementGrade(unsigned int decrement) {
	if (this->_grade + decrement > MAX_GRADE)
		throw Bureaucrat::GradeTooLowException(); // Grade too low
	else
		this->_grade += decrement;
}

// Exception messages
const char	*Bureaucrat::GradeTooHighException::what () const throw () { return("Range too high"); }
const char	*Bureaucrat::GradeTooLowException::what () const throw () { return("Range too low"); }

// /overload Operator "<<" to display Bureaucrat info
std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat) {
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return (out);
}
