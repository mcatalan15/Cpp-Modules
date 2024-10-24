/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 10:34:08 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/10/24 10:52:56 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

# define MAX_GRADE	150
# define MIN_GRADE	1

# define MAGENTA "\033[35m"
# define RESET "\033[0m"
# define  CYAN "\033[36m" 

class  Bureaucrat {

	private:
		const std::string	_name;	// Const because it should not be modified
		unsigned int		_grade;	// Grade between 1 and 150

	public:
		// Constructors, destructor, operator '=' (canonical form)
		Bureaucrat();	
		Bureaucrat(const std::string &name, const unsigned int grade);
		Bureaucrat(const Bureaucrat &cpy);
		~Bureaucrat();
		
		Bureaucrat&	operator=(const Bureaucrat &cpy);
		
		// Getters
		std::string	getName() const;
		unsigned int	getGrade() const;
		
		// Grade increment and decrement functions
		void		incrementGrade();
		void		decrementGrade();
		void		incrementGrade(unsigned int increment);
		void		decrementGrade(unsigned int decrement);

		// Custom exceptions
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

