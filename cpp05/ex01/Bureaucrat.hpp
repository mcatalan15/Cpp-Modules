/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:56:38 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/10/24 12:10:54 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include "Form.hpp"

# define MAX_GRADE	150
# define MIN_GRADE	1

# define MAGENTA "\033[35m"
# define RESET "\033[0m"
# define CYAN "\033[36m"  
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[38:5:220m"

using std::string;

class Form;

class  Bureaucrat {

	private:
		const string	_name;
		unsigned int	_grade;

	public:
		// Orthodox Canonical Form
		Bureaucrat();	
		Bureaucrat(const string &name, const unsigned int grade);
		Bureaucrat(const Bureaucrat &cpy);
		~Bureaucrat();
		
		Bureaucrat		&operator=(const Bureaucrat &cpy);
		
		// Getters
		string			getName() const;
		unsigned int	getGrade() const;
		
		// Functions decrement and increment grade
		void			incrementGrade();
		void			decrementGrade();
		void			incrementGrade(unsigned int increment);
		void			decrementGrade(unsigned int decrement);

		// Sign form function
		void			signForm(Form &form);

		// Exceptions
		class GradeTooLowException : public std::exception {
			public:
				const char *what() const throw();
		};

		class GradeTooHighException : public std::exception {
			public:
				const char *what() const throw();
		};
};

// Overload operator '<<' to print Bureaucrat info
std::ostream&	operator<<(std::ostream &os, const Bureaucrat &b);

#endif

