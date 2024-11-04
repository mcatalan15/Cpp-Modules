/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 10:21:07 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/11/04 19:41:41 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP 
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include "AForm.hpp"

// Minimum grade to sign the form and execute the form
# define MIN_GRADE_SIGN_PP 25
# define MIN_GRADE_EXECUTE_PP 5

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
class PresidentialPardonForm : public AForm{
	
	private:
 		const string	_target;
	
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const string & target);
		PresidentialPardonForm(const PresidentialPardonForm & src);
		~PresidentialPardonForm();

		PresidentialPardonForm & operator=(const PresidentialPardonForm & src);

		string 	getTarget() const;

		void	executeConcreteForm() const;
		AForm *clone();
};

std::ostream &	operator<<(std::ostream & out, const PresidentialPardonForm & SCform);

#endif
