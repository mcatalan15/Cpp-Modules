/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:56:47 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/10/21 11:56:48 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


void	shrubberyCreationFormTest(){
	
	std::cout << std::endl << CYAN << "----- Shrubbery Creation Form Test----- " << RESET << std::endl;
	
	std::cout << std::endl << MAGENTA << "Try to execute ShrubberyCreationForm" << RESET << std::endl;
	try {
		ShrubberyCreationForm SCForm = ShrubberyCreationForm("home");
		Bureaucrat Julia = Bureaucrat("Julia", 14);
		SCForm.execute(Julia);
	}
	catch (std::out_of_range & e){
		std::cout << RED << "\tcatch: " << e.what() << RESET << std::endl;
	}
	catch (std::runtime_error & e){
		std::cout << RED << "\tcatch: " << e.what() << RESET << std::endl;
	}
	catch (std::exception & e){
		std::cout << RED << "\tcatch: " << e.what() << RESET << std::endl;
	}


	std::cout << std::endl << MAGENTA << "Try to execute ShrubberyCreationForm with too low grade" << RESET << std::endl;
	try {
		ShrubberyCreationForm SCForm = ShrubberyCreationForm("home");
		Bureaucrat Pepe = Bureaucrat("Pepe", 140);
		SCForm.execute(Pepe);
	}
	catch (std::out_of_range & e){
		std::cout << RED << "\tcatch: " << e.what() << RESET << std::endl;
	}
	catch (std::runtime_error & e){
		std::cout << RED << "\tcatch: " << e.what() << RESET << std::endl;
	}
	catch (std::exception & e){
		std::cout << RED << "\tcatch: " << e.what() << RESET << std::endl;
	}


	std::cout << std::endl << MAGENTA << "Try to execute ShrubberyCreationForm wich is signed" << RESET << std::endl;
	try {
		ShrubberyCreationForm SCForm = ShrubberyCreationForm("home");
		Bureaucrat Pepe = Bureaucrat("Pepe", 14);
		SCForm.beSigned(Pepe);
		SCForm.execute(Pepe);
	}
	catch (std::out_of_range & e){
		std::cout << RED << "\tcatch: " << e.what() << RESET << std::endl;
	}
	catch (std::runtime_error & e){
		std::cout << RED << "\tcatch: " << e.what() << RESET << std::endl;
	}
	catch (std::exception & e){
		std::cout << RED << "\tcatch: " << e.what() << RESET << std::endl;
	}

}


void	robotomyRequestFormTest(){
	std::cout << std::endl << CYAN << "----- Robotomy Request Form Test----- " << RESET << std::endl;
	
	std::cout << std::endl << MAGENTA << "Try to execute robotomyRequestForm" << RESET << std::endl;
	try {
		RobotomyRequestForm RRForm = RobotomyRequestForm("home");
		Bureaucrat Julia = Bureaucrat("Julia", 14);
		RRForm.execute(Julia);
	}
	catch (std::out_of_range & e){
		std::cout << RED << "\tcatch: " << e.what() << RESET << std::endl;
	}
	catch (std::runtime_error & e){
		std::cout << RED << "\tcatch: " << e.what() << RESET << std::endl;
	}
	catch (std::exception & e){
		std::cout << RED << "\tcatch: " << e.what() << RESET << std::endl;
	}


	std::cout << std::endl << MAGENTA << "Try to execute robotomyRequestForm with too low grade" << RESET << std::endl;
	try {
		RobotomyRequestForm RRForm = RobotomyRequestForm("home");
		Bureaucrat Julia = Bureaucrat("Julia", 140);
		RRForm.execute(Julia);
	}
	catch (std::out_of_range & e){
		std::cout << RED << "\tcatch: " << e.what() << RESET << std::endl;
	}
	catch (std::runtime_error & e){
		std::cout << RED << "\tcatch: " << e.what() << RESET << std::endl;
	}
	catch (std::exception & e){
		std::cout << RED << "\tcatch: " << e.what() << RESET << std::endl;
	}


	std::cout << std::endl << MAGENTA << "Try to execute robotomyRequestForm wich is signed" << RESET << std::endl;
	try {
		RobotomyRequestForm RRForm = RobotomyRequestForm("home");
		Bureaucrat Julia = Bureaucrat("Julia", 14);
		RRForm.execute(Julia);
		RRForm.beSigned(Julia);
		RRForm.execute(Julia);
	}
	catch (std::out_of_range & e){
		std::cout << RED << "\tcatch: " << e.what() << RESET << std::endl;
	}
	catch (std::runtime_error & e){
		std::cout << RED << "\tcatch: " << e.what() << RESET << std::endl;
	}
	catch (std::exception & e){
		std::cout << RED << "\tcatch: " << e.what() << RESET << std::endl;
	}
}

void	presidentialPardonFormTest(){
	std::cout << std::endl << CYAN << "----- Presidential Pardo Form Test----- " << RESET << std::endl;
	
	std::cout << std::endl << MAGENTA << "Try to execute presidentialPardonForm" << RESET << std::endl;
	try {
		PresidentialPardonForm PPForm = PresidentialPardonForm("home");
		Bureaucrat Julia = Bureaucrat("Julia", 14);
		PPForm.execute(Julia);
	}
	catch (std::out_of_range & e){
		std::cout << RED << "\tcatch: " << e.what() << RESET << std::endl;
	}
	catch (std::runtime_error & e){
		std::cout << RED << "\tcatch: " << e.what() << RESET << std::endl;
	}
	catch (std::exception & e){
		std::cout << RED << "\tcatch: " << e.what() << RESET << std::endl;
	}

	std::cout << std::endl << MAGENTA << "Try to execute presidentialPardonForm with too low grade" << RESET << std::endl;
	try {
		PresidentialPardonForm PPForm = PresidentialPardonForm("home");
		Bureaucrat Julia = Bureaucrat("Julia", 140);
		PPForm.execute(Julia);
	}
	catch (std::out_of_range & e){
		std::cout << RED << "\tcatch: " << e.what() << RESET << std::endl;
	}
	catch (std::runtime_error & e){
		std::cout << RED << "\tcatch: " << e.what() << RESET << std::endl;
	}
	catch (std::exception & e){
		std::cout << RED << "\tcatch: " << e.what() << RESET << std::endl;
	}

	std::cout << std::endl << MAGENTA << "Try to execute robotomyRequestForm wich is signed" << RESET << std::endl;
	try {
		PresidentialPardonForm PPForm = PresidentialPardonForm("home");
		Bureaucrat Julia = Bureaucrat("Julia", 2);
		PPForm.execute(Julia);
		PPForm.beSigned(Julia);
		PPForm.execute(Julia);
	}
	catch (std::out_of_range & e){
		std::cout << RED << "\tcatch: " << e.what() << RESET << std::endl;
	}
	catch (std::runtime_error & e){
		std::cout << RED << "\tcatch: " << e.what() << RESET << std::endl;
	}
	catch (std::exception & e){
		std::cout << RED << "\tcatch: " << e.what() << RESET << std::endl;
	}
}

void	bureaucratTest(){
	
	std::cout << std::endl << CYAN << "----- Bureaucrat Test----- " << RESET << std::endl;
	
	try {
		Bureaucrat Julia = Bureaucrat("Julia", 75);
		ShrubberyCreationForm SCForm = ShrubberyCreationForm("home");
		RobotomyRequestForm RRForm = RobotomyRequestForm("home");
		std::cout << std::endl << MAGENTA << "Try to sign ShrubberyCreationForm" << RESET << std::endl;
		Julia.signForm(SCForm);
		std::cout << std::endl << MAGENTA << "Try to sign RobotomyRequestForm" << RESET << std::endl;
		Julia.signForm(RRForm);
		std::cout << std::endl << MAGENTA << "Try to execute RobotomyRequestForm" << RESET << std::endl;
		Julia.executeForm(RRForm);
		Julia.incrementGrade(70);
		std::cout << std::endl << MAGENTA << "Try to execute RobotomyRequestForm" << RESET << std::endl;
		Julia.executeForm(RRForm);
	}
	catch (std::out_of_range & e){
		std::cout << RED << "\tcatch: " << e.what() << RESET << std::endl;
	}
	catch (std::runtime_error & e){
		std::cout << RED << "\tcatch: " << e.what() << RESET << std::endl;
	}
	catch (std::exception & e){
		std::cout << RED << "\tcatch: " << e.what() << RESET << std::endl;
	}


}

void	testCanonicalForm(){

	std::cout << std::endl << std::endl << CYAN << "----- Test canonical form ----- " << RESET << std::endl;
	try {
		ShrubberyCreationForm SCForm = ShrubberyCreationForm("Home");
		RobotomyRequestForm RRForm = RobotomyRequestForm("News");
		PresidentialPardonForm PPForm = PresidentialPardonForm("Work");
		std::cout << std::endl << MAGENTA << "Check << operator" << RESET << std::endl;	
		std::cout << SCForm << std::endl;
		std::cout << RRForm << std::endl;
		std::cout << PPForm << std::endl;
	}
	catch (std::out_of_range & e){
		std::cout << RED << "\tcatch: " << e.what() << RESET << std::endl;
	}
}


int main() {
	
	shrubberyCreationFormTest();
	robotomyRequestFormTest();
	presidentialPardonFormTest();

	bureaucratTest();

	testCanonicalForm();

	return (0);
}
