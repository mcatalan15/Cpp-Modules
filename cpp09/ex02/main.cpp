#include "PmergeMe.hpp"

int main(int argc, char **argv) {
		if (argc < 2) {
			std::cout << "Usage: " << argv[0] << " <numbers>" << std::endl;
			return 1;
		} else if (argc > 3001) {
			std::cout << "Error: N numbers must be less than 3000." << std::endl;
			return 1;
		}
		try {
			// Vector
			PmergeMe sorter(argv);
			std::cout << "Before sorting: ";
			sorter.printV();
			
			sorter.sortV();
			
			std::cout << "After sorting: ";
			sorter.printV();
			sorter.printT(argc - 1, 1);
			
			//Deque
			sorter.sortD();
			sorter.printT(argc - 1, 0);
			
		} catch (PmergeMe::errorException &e) {
			std::cerr << e.what() << std::endl;
			return 1;
		}
		return 0;
}