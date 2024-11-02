/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 10:21:03 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/11/02 17:37:17 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include "AForm.hpp"

// Minimum grade to sign the form and execute the form
#define MIN_GRADE_SIGN_RR 72
#define MIN_GRADE_EXECUTE_RR 45

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
class RobotomyRequestForm : public AForm {
	private:
		const string _target;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const string &target);
		RobotomyRequestForm(const RobotomyRequestForm &src);
		~RobotomyRequestForm();

		RobotomyRequestForm &operator=(const RobotomyRequestForm &src);

		string getTarget() const;

		void executeConcreteForm() const;
};

std::ostream &operator<<(std::ostream &out, const RobotomyRequestForm &SCform);

#endif
