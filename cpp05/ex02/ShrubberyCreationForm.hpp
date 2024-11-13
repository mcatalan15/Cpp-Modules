/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 10:21:34 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/11/02 17:42:02 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <fstream>
#include "AForm.hpp"

// Minimum grade to sign the form and execute the form
#define MIN_GRADE_SIGN_SC 145
#define MIN_GRADE_EXECUTE_SC 137

using std::string;

/*
	This class will be a child of AForm.
	private:
		- target: the target of the form
	public:
		- Orthodox Canonical Form
		- Getters
		- Functions (executeConcreteForm)
	
	Also we will overload the operator "<<" to print the form information.
*/
class ShrubberyCreationForm : public AForm {
	private:
		const string _target;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const string &target);
		ShrubberyCreationForm(const ShrubberyCreationForm &src);
		~ShrubberyCreationForm();

		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &src);

		string getTarget() const;

		void executeConcreteForm() const;
};

std::ostream &operator<<(std::ostream &out, const ShrubberyCreationForm &SCform);

#endif
