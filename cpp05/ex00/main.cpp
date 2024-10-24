/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 10:34:00 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/10/24 10:50:41 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp" 

// Test: Create Bureaucrat with correct grade
void	constructorCorrectGrade() {
	std::cout << std::endl << CYAN << "----- Test correct grade ----- " << RESET << std::endl;
	try {
		Bureaucrat("Marc", 120); // Valid grade
	}
	catch (std::exception & e) { // In case of exception print the message
		std::cout << "\tcatch: " << e.what() << std::endl;
	}
}

// Test: Create Bureaucrat with too high grade
void	constructorTooHighGrade() {
	std::cout << std::endl << CYAN << "----- Test too high grade ----- " << RESET << std::endl;
	try {
		Bureaucrat("Marc", 0);	// Invalid grade: Trigger GradeTooHighException
	}
	catch (std::exception & e) { // Catch and display the exception
		std::cout << "\tcatch: " << e.what() << std::endl;
	}
}

// Test: Create Bureaucrat with too low grade
void	constructorTooLowGrade() {
	std::cout << std::endl << CYAN << "----- Test too low grade ----- " << RESET << std::endl;
	try {
		Bureaucrat("Marc", 987); // Invalid grade: Trigger GradeTooLowException
	}
	catch (std::exception & e) { // Catch and display the exception
		std::cout << "\tcatch: " << e.what() << std::endl;
	}
}

// Test: Increment grade
void	testIncrementGrade() {
	std::cout << std::endl << std::endl << CYAN << "----- Test increment grade ----- " << RESET << std::endl << std::endl;
	try {
		Bureaucrat Marc = Bureaucrat("Marc", 120); // Start with valid grade
		std::cout << Marc << std::endl;
		std::cout << MAGENTA << "Try to increment 119." << RESET << std::endl;
		Marc.incrementGrade(119); // Increment by 119, expected grade 1
		std::cout << Marc << std::endl << std::endl;
		std::cout << MAGENTA << "Try to increment 1." << RESET << std::endl;
		Marc.incrementGrade(); // Increment further by 1, should throw GradeTooHighException
		std::cout << Marc << std::endl << std::endl;
	}
	catch (std::exception & e) { // Catch and display the exception
		std::cout << "\tcatch: " << e.what() << std::endl;
	}
}

// Test: Decrementing grade
void	testDecrementGrade() {
	std::cout << std::endl << std::endl << CYAN << "----- Test decrement grade ----- " << RESET << std::endl << std::endl;
	try {
		Bureaucrat Marc = Bureaucrat("Marc", 120); // Start with valid grade
		std::cout << Marc << std::endl;
		std::cout << MAGENTA << "Try to decrement 30." << RESET << std::endl;
		Marc.decrementGrade(30); // Decrement by 30, expected grade 150
		std::cout << Marc << std::endl << std::endl;
		std::cout << MAGENTA << "Try to decrement 1." << RESET << std::endl;
		Marc.decrementGrade(); // Decrement further by 1, should throw GradeTooLowException
		std::cout << Marc << std::endl << std::endl;
	}
	catch (std::exception & e) { // Catch and display the exception
		std::cout << "\tcatch: " << e.what() << std::endl;
	}
}

// Test: Canonical form
void	testCanonicalForm(){
	std::cout << std::endl << std::endl << CYAN << "----- Test canonical form ----- " << RESET << std::endl << std::endl;
	try {
		Bureaucrat Marc = Bureaucrat("Marc", 120); // Create Bureaucrat Marc
		Bureaucrat Pepe = Bureaucrat("Pepe", 113); // Create Bureaucrat Pepe
		Pepe = Marc; // Assign Marc to Pepe (assignment operator)
		std::cout << Pepe << std::endl << std::endl; // Should print Marc's info
		std::cout << Marc << std::endl << std::endl;
	}
	catch (std::exception & e) { // Catch and display the exception
		std::cout << "\tcatch: " << e.what() << std::endl;
	}
}

// Main function to run tests
int main() {	
	constructorCorrectGrade();
	constructorTooHighGrade();
	constructorTooLowGrade();

	testIncrementGrade();
	testDecrementGrade();

	testCanonicalForm();

	return (0);
}

