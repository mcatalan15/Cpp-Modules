#include <iostream>
#include "Sample.hpp"

int	main() {

	Sample instance;

	instance.foo = 42;
	std::cout << "instance.foo " << instance.foo << std::end;;

	instance.bar();

	return 0;
}
