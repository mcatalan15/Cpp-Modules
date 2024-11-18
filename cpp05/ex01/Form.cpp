/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:56:41 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/11/15 18:36:47 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

using std::string;

// Default constructor
Form::Form() : _name("uname"), _isSign(false), _signGrade(MAX_GRADE), _execGrade(MAX_GRADE) {}

// Constructor
Form::Form(const string &name, unsigned int gradeToSign, unsigned int gradeToExecute)
	: _name(name), _isSign(false), _signGrade(gradeToSign), _execGrade(gradeToExecute) {
	if (gradeToSign < MIN_GRADE || gradeToExecute < MIN_GRADE)
		throw Form::GradeTooHighException("Form cannot be constructed: ");
	else if (gradeToSign > MAX_GRADE || gradeToExecute > MAX_GRADE)
		throw Form::GradeTooLowException("Form cannot be constructed: ");
}

// Copy constructor
Form::Form(const Form &src) : _name(src._name), _isSign(src._isSign), _signGrade(src._signGrade), _execGrade(src._execGrade) {}

// Destructor
Form::~Form() {}

// Assignment Operator '='
Form &Form::operator=(const Form &src) {
	if (this != &src)
		this->_isSign = src.getIsSigned();
	return (*this);
}

// Getters
string Form::getName() const { return (_name); }
bool Form::getIsSigned() const { return (_isSign); }
unsigned int Form::getGradeToSign() const { return (_signGrade); }
unsigned int Form::getGradeToExecute() const { return (_execGrade); } 

// Method to sign the form by a bureaucrat
void Form::beSigned(Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > this->_signGrade)
		throw Form::GradeTooLowException("Form cannot be signed: "); // Grade too low
	if (this->_isSign)
		throw Form::FormIsSignedException("Form is already signed: "); // Form already signed
	else {
		this->_isSign = true; // Sign the form & print message
		std::cout << GREEN << bureaucrat.getName() << " has signed " << this->_name << RESET << std::endl;
	}
}

/*
	Exceptions:
	This method defines exceptions as public classes inheriting exception types like `std::out_of_range`.
	Custom error messages are passed dynamically through constructors, allowing greater flexibility.
	Advantages: Highly customizable and reusable across different classes or contexts.
	Drawbacks: Reduced encapsulation compared to nested classes.
*/
Form::GradeTooHighException::GradeTooHighException(string error_msg) : std::out_of_range(error_msg + "Grade too high.") {}
Form::GradeTooLowException::GradeTooLowException(string error_msg) : std::out_of_range(error_msg + "Grade too low.") {}
Form::FormIsSignedException::FormIsSignedException(string error_msg) : std::runtime_error(error_msg + "Form already signed.") {}

// Overload insertion operator '<<' to output the forrm info
std::ostream &operator<<(std::ostream &out, const Form &form) {
	out << YELLOW << "Form " << form.getName() << " (Sign Grade: " << form.getGradeToSign() << ", Execute Grade: " << form.getGradeToExecute() << ")";
	if (form.getIsSigned())
		out << " [Signed]" << RESET; // Print signed if form is signed
	else
		out << " [Unsigned]" << RESET; // Print unsigned if form is not signed
	return (out);
}
