/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 10:21:19 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/11/02 17:08:07 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

using std::string;

// Default constructor
AForm::AForm() : _name("uname"), _isSigned(false), _gradeToSign(MAX_GRADE),
				 _gradeToExcetute(MAX_GRADE) {}

/*
	Construtor
	This constructor will check if the grade is between the limits.
	- If the grade is lower than 1, it will throw a GradeTooHighException.
	- If the grade is higher than 150, it will throw a GradeTooLowException.
*/
AForm::AForm(const string &name, const unsigned int gradeToSign,
			 const unsigned int gradeToExecute) : _name(name), _isSigned(false) {
	if (gradeToSign < MIN_GRADE || gradeToExecute < MIN_GRADE)
		throw AForm::GradeTooHighException("");
	else if (gradeToSign > MAX_GRADE || gradeToExecute > MAX_GRADE)
		throw AForm::GradeTooLowException("");
	else {
		this->_gradeToSign = gradeToSign;
		this->_gradeToExcetute = gradeToExecute;
	}
}

// copy constructor
AForm::AForm(const AForm &src) {
	*this = src;
}

AForm::~AForm() {}

// operator "="
AForm &AForm::operator=(const AForm &src){
	if (this != &src) {
		this->_isSigned = src.getIsSigned();
		this->_gradeToSign = src.getGradeToSign();
		this->_gradeToExcetute = src.getGradeToExecute();
	}
	return (*this);
}

// GETTERS
// Get name of the form
string AForm::getName() const {
	return (_name);
}
// Get if the form is signed. Signed = true, not signed = false
bool AForm::getIsSigned() const {
	return (_isSigned);
}
// Get the grade to sign the form
unsigned int AForm::getGradeToSign() const {
	return (_gradeToSign);
}
// Get the grade to execute the form
unsigned int AForm::getGradeToExecute() const {
	return (_gradeToExcetute);
}

// SETTERS
// Set if the form is signed
void AForm::setIsSigned(const bool isSigned) {
	this->_isSigned = isSigned;
}
// Set the grade to sign the form
void AForm::setGradeToSign(const unsigned int &gradeToSign) {
	this->_gradeToSign = gradeToSign;
}
// Set the grade to execute the form
void AForm::setGradeToExecute(const unsigned int &getGradeToExecute) {
	this->_gradeToExcetute = getGradeToExecute;
}

// FUNCTIONS
/*
	This function will sign the form if the bureaucrat has the right grade or if the form is not signed.
	- If the bureaucrat has a lower grade than the grade to sign the form, it will throw a GradeTooLowException.
	- If the form is already signed, it will throw a FormIsSignedException.
*/
void AForm::beSigned(Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw AForm::GradeTooLowException(" ");
	if (this->_isSigned)
		throw AForm::FormIsSignedException("");
	else {
		this->_isSigned = true;
		std::cout << GREEN << bureaucrat.getName() << " has signed " << this->_name << RESET << std::endl;
	}
}

/*
	This function will execute the form if the bureaucrat has the right grade and the form is signed.
	- If the form is not signed, it will throw a FormIsSignedException.
	- If the bureaucrat has a lower grade than the grade to execute the form, it will throw a GradeTooLowException.
*/
void AForm::execute(Bureaucrat const &executor) const {
	if (_isSigned) {
		throw AForm::FormIsSignedException("");
	}
	if (executor.getGrade() > getGradeToExecute())
	{
		throw AForm::GradeTooLowException("");
	}
	executeConcreteForm();
}

// exceptions
// This exception will be thrown if the grade is higher than 150 when creating a form
AForm::GradeTooHighException::GradeTooHighException(string error_msg) : std::out_of_range(error_msg + "Range too high.") {};
AForm::GradeTooLowException::GradeTooLowException(string error_msg) : std::out_of_range(error_msg + "Range too low.") {};
AForm::FormIsSignedException::FormIsSignedException(string error_msg) : std::runtime_error(error_msg + "Form is already signed.") {};
