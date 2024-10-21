#include "Form.hpp"

using std::string;

// Default constructor
Form::Form() : _name("uname"), _isSign(false), _gradeToSign(MAX_GRADE), _gradeToExecute(MAX_GRADE) {}

// Constructor
Form::Form(const string &name, const unsgined int gradeToSign, const unsigned int gradeToExecute) : _name(name), _isSign(false) {
	if (gradeToSign < MIN_GRADE || gradeToExecute < MIN_GRADE)
		throw Form::GradeTooHighException("Form cannot be constructed.");
	else if (gradeToSign < MIN_GRADE || gradetoExecute > MAX_GRADE)
		throw From::GradeTooLowException("Form cannot be constructed. ");
	else {
		this->_gradeToSign = gradeToSign;
		this->_gradeToExecute = gradeToExecute;
	}
}

// Copy constructor
Form::Form(const Form &src) { *this = src; }

// Destructor
Form::~Form() {}

// Copy operator "="
Form &Form::operator=(const Form &src) {
	if (this != &src) {
		this->_isSign = src.getIsSigned();
		this->_gradeToSign = src.getGradeToSign();
		this->_gradeToExecute = src.getGradeToExecute();
	}
	return (*this);
}

// Getters
string	Form::getName() const { return(_name); }

bool	Form::getIsSigned() const { return(_isSign); }

unsigned int	Form::getGradeToSign() const { return(_gradeToSign); }

unsigned int	Form::getGradeToExecute() const { return(_gradeToExecute); }


// Setters
void	Form::setIsSigned(const bool isSigned) { this->_isSign = isSigned; }

void	Form::setGradeToSign(const unsigned int &gradeToSign) { this->_gradeToSign = gradeToSign; }

void	Form::setGradeToExecute(const unsigned int &gradeToExecute) { this->_gradeToExecute = gradeToExecute; }


// Functions
void	Form::beSigned(Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw From::GradeTooLowException("Form can not be signed.");
	if (this->_isSign)
		throw From::FormIsSignedException("Form is already signed.");
	else {
		this->_isSign = true;
		std::cout << GREEN << bureaucrat.getName() << " has signed " << this->_name << RESET << std::endl;
	}
}

// Exceptions
Form::GradeTooHighException::GradeTooHighException(string error_msg) : std::out_of_range(error_msg + "Range too high.") {};

Form::GradeTooLowException::GradeTooLowException(string error_msg) : std::out_of_range(error_msg + "Range too low.") {};

Form::FormIsSignedException::FormIsSignedException(string error_msg) : std::runtime_error(error_msg + "Form is already signed") {};

// Operator "<<"
std::ostream &operator<<(std::ostream &out, const Form &form) {
	out << YELLOW << "[" << form.getName() << "] Grade to sign: " << form.getGradeToSign() \
		<< " | Grade to execute: " << form.getGradeToExecute();
	if (form.getIsSigned())
		out << " | Form is signed." << RESET << std::endl;
	else
		out << " | Form is NOT signed." << RESET << std::endl;
	return (out);
}

