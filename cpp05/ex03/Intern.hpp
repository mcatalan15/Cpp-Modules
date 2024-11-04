/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 19:09:44 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/11/04 19:22:08 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

using std::string;

class Intern {
	public:
		Intern();
		Intern(const string &target);
		Intern(const Intern &src);
		~Intern();

		Intern &operator=(const Intern &src);

		AForm *makeForm(const string &forName, const string &target) const;
};

#endif
