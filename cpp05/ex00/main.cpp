#include "Bureaucrat.hpp" 

void	constructorCorrectGrade(){
	
	std::cout << std::endl << CYAN << "----- Test correct grade ----- " << RESET << std::endl;
	try {
		Bureaucrat("Marc", 120);
	}
	catch (std::exception & e){
		std::cout << "\tcatch: " << e.what() << std::endl;
	}
}

void	constructorTooHighGrade(){

	std::cout << std::endl << CYAN << "----- Test too high grade ----- " << RESET << std::endl;
	try {
		Bureaucrat("Marc", 0);	
	}
	catch (std::exception & e){
		std::cout << "\tcatch: " << e.what() << std::endl;
	}
}

void	constructorTooLowGrade(){
	
	std::cout << std::endl << CYAN << "----- Test too low grade ----- " << RESET << std::endl;
	try {
		Bureaucrat("Marc", 987);
	}
	catch (std::exception & e){
		std::cout << "\tcatch: " << e.what() << std::endl;
	}
}

void	testIncrementGrade(){
	
	std::cout << std::endl << std::endl << CYAN << "----- Test increment grade ----- " << RESET << std::endl << std::endl;
	try {
		Bureaucrat Marc = Bureaucrat("Marc", 120);
		std::cout << Marc << std::endl;
		std::cout << MAGENTA << "Try to increment 119." << RESET << std::endl;
		Marc.incrementGrade(119);
		std::cout << Marc << std::endl << std::endl;
		std::cout << MAGENTA << "Try to increment 1." << RESET << std::endl;
		Marc.incrementGrade();
		std::cout << Marc << std::endl << std::endl;
	}
	catch (std::exception & e){
		std::cout << "\tcatch: " << e.what() << std::endl; }
}

void	testDecrementGrade(){
	
	std::cout << std::endl << std::endl << CYAN << "----- Test decrement grade ----- " << RESET << std::endl << std::endl;
	try {
		Bureaucrat Marc = Bureaucrat("Marc", 120);
		std::cout << Marc << std::endl;
		std::cout << MAGENTA << "Try to decrement 30." << RESET << std::endl;
		Marc.decrementGrade(30);
		std::cout << Marc << std::endl << std::endl;
		std::cout << MAGENTA << "Try to decrement 1." << RESET << std::endl;
		Marc.decrementGrade();
		std::cout << Marc << std::endl << std::endl;
	}
	catch (std::exception & e){
		std::cout << "\tcatch: " << e.what() << std::endl;
	}
}

void	testCanonicalForm(){
	std::cout << std::endl << std::endl << CYAN << "----- Test canonical form ----- " << RESET << std::endl << std::endl;
	try {
		Bureaucrat Marc = Bureaucrat("Marc", 120);
		Bureaucrat Pepe = Bureaucrat("Pepe", 113);
		Pepe = Marc;
		std::cout << Pepe << std::endl << std::endl;
		std::cout << Marc << std::endl << std::endl;
	}
	catch (std::exception & e){
		std::cout << "\tcatch: " << e.what() << std::endl;
	}
}


int main() {
	
	constructorCorrectGrade();
	constructorTooHighGrade();
	constructorTooLowGrade();

	testIncrementGrade();
	testDecrementGrade();

	testCanonicalForm();

	return (0);
}

