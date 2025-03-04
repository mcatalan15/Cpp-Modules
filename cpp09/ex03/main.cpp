#include "PmergeMe.hpp"
#include <ctime>

int main(int argc, char **argv) {
	if (argc < 2) {
		std::cerr << "Usage: " << argv[0] << " <number1> <number2> ... <numberN>" <<std::endl;
		return 1;
	}
	try {
		PmergeMe sorter(argv);
		std::cout << "Before: ";
		sorter.printVect();
		std::cout << std::endl;

		clock_t start = clock();
		sorter.mergeInsertSort();
		clock_t end = clock();

		double duration = (double)(end - start) / CLOCKS_PER_SEC * 1000000;
		
		std::cout << "\nAfter: ";
		sorter.printVect();
		std::cout << std::endl;
		
		std::cout << "Time " << duration << " us" <<std::endl;
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return 0;
}