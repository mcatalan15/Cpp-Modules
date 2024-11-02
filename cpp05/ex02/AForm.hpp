/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 10:21:15 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/11/02 17:11:42 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP 
# define AFORM_HPP

# include <iostream>
# include <fstream>
# include "Bureaucrat.hpp"

using std::string;

// We need to declare the Bureaucrat class to avoid circular dependencies
// Circular dependencies occur when two classes depend on each other.
class Bureaucrat;

/*
	This class will be the parent class of the forms.
	private:
		- name: the name of the form
		- isSigned: a boolean to know if the form is signed
		- gradeToSign: the grade needed to sign the form
		- gradeToExcetute: the grade needed to execute the form
	public:
		- Orthodox Canonical Form
		- Getters
		- Setters
		- Functions (beSigned, execute, executeConcreteForm)
		- Exceptions
*/
class AForm {
	private:
		const string _name;
		bool _isSigned;
		unsigned int _gradeToSign;
		unsigned int _gradeToExcetute;

	public:
		AForm();
		AForm(const string &name, const unsigned int gradeToSign,
			const unsigned int gradeToExecute);
		AForm(const AForm &src);
		virtual ~AForm();

		AForm &operator=(const AForm &src);

		string getName() const;
		bool getIsSigned() const;
		unsigned int getGradeToSign() const;
		unsigned int getGradeToExecute() const;

		void setIsSigned(const bool isSigned);
		void setGradeToSign(const unsigned int &gradeToSign);
		void setGradeToExecute(const unsigned int &gradeToExecute);

		void beSigned(Bureaucrat &bureaucrat);
		void execute(Bureaucrat const &executor) const;
		virtual void executeConcreteForm() const = 0;

		class GradeTooHighException : public std::out_of_range {
			public:
				GradeTooHighException(string error_msg);
		};
		class GradeTooLowException : public std::out_of_range {
			public:
				GradeTooLowException(string error_msg);
		};
		class FormIsSignedException : public std::runtime_error {
			public:
				FormIsSignedException(string error_msg);
		};
};

#endif
