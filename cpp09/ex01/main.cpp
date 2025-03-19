#include "RPN.hpp"

int	main(int argc, char **argv) {
	try {
		if (argc != 2)
			throw std::invalid_argument("Invalid number of arguments");
		RPN rpn(argv[1]);
	} catch (std::exception &e){
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
