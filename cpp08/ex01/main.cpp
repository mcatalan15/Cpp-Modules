#include "Span.hpp" 

void mandatoryTest(){
	std::cout << std::endl << "----- Mandatory test ----- " << std::endl;
	Span sp = Span(5);
	try {
		sp.addNumber(-2147483648);
		sp.addNumber(10);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;	
	}
	catch(const std::runtime_error& e){
		std::cout << RED << "Error: " << e.what() << RESET << std:: endl;
	}
}

void spanIsFullTest(){
	std::cout << std::endl << "----- Full span test ----- " << std::endl;
	Span sp = Span(2);
	try {
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;	
	}
	catch(const std::runtime_error& e){
		std::cout << RED << "Error: " << e.what() << RESET << std:: endl;
	}
}

void notEnoughNumbers(){
	std::cout << std::endl << "----- Short span test ----- " << std::endl;
	Span sp = Span(5);
	try {
		sp.addNumber(6);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;	
	}
	catch(const std::runtime_error& e){
		std::cout << RED << "Error: " << e.what() << RESET << std:: endl;
	}
}

void randomFillSpanTest(){
	std::cout << std::endl << "----- Random Fill Span test ----- " << std::endl;
	Span sp = Span(10000);
	sp.addRangeNumbers();
	try {
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;	
	}
	catch(const std::runtime_error& e){
		std::cout << RED << "Error: " << e.what() << RESET << std:: endl;
	}
	std::cout << "Span size: " << sp.getSpan().size() << std::endl;
}

int main() {

	mandatoryTest();
	spanIsFullTest();
	notEnoughNumbers();
	randomFillSpanTest();
	return (0);
}

