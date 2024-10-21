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
		const std::string	_name;
		unsigned int		_grade;

	public:
		Bureaucrat();	
		Bureaucrat(const std::string &name, const unsigned int grade);
		Bureaucrat(const Bureaucrat &cpy);
		~Bureaucrat();
		
		Bureaucrat&	operator=(const Bureaucrat &cpy);
		std::string	getName() const;
		unsigned int	getGrade() const;
		void		incrementGrade();
		void		decrementGrade();
		void		incrementGrade(unsigned int increment);
		void		decrementGrade(unsigned int decrement);

		class GradeTooLowException : public std::exception {
			public:
				const char *what() const throw();
		};

		class GradeTooHighException : public std::exception {
			public:
				const char *what() const throw();
		};
};

std::ostream&	operator<<(std::ostream &os, const Bureaucrat &b);

#endif

