#include "Bureaucrat.hpp"

// Default constructor
Bureaucrat::Bureaucrat() : _name("uname"), _grade(MAX_GRADE) {}

// Constructor
Bureaucrat::Bureaucrat(const std::string &name, const unsigned int grade) : _name(name) {
	if (grade < MIN_GRADE)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > MAX_GRADE)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade = grade;
}

// Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat &src) { *this = src; }

// Destructor
Bureaucrat::~Bureaucrat() {}

// Operator '='
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src) {
	if (this != &src)
		this->_grade = src.getGrade();
	return (*this);
}

// Getters
std::string Bureaucrat::getName() const { return (_name); }

unsigned int Bureaucrat::getGrade() const { return (_grade); }

// Functions
void	Bureaucrat::incrementGrade() {
	if (this->_grade - 1 < MIN_GRADE)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade--;
}

void	Bureaucrat::incrementGrade(unsigned int increment) {
	if (this->_grade < MIN_GRADE + increment)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade -= increment;
}

void	Bureaucrat::decrementGrade() {
	if (this->_grade + 1 > MAX_GRADE)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade++;
}

void	Bureaucrat::decrementGrade(unsigned int decrement) {
	if (this->_grade + decrement > MAX_GRADE)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade += decrement;
}

// Exception
const char	*Bureaucrat::GradeTooHighException::what () const throw () { return("Range too high"); }

const char	*Bureaucrat::GradeTooLowException::what () const throw () { return("Range too low"); }

// Operator "<<"
std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat) {
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return (out);
}

