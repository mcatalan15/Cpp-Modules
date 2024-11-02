#include <iostream>
#include <string>

using std::string;

void	byPtr(string *str) {
	*str += " and ponies";
}

void	byConstPtr(string const *str) {
	std::cout << *str << std::endl;
}

void	byRef(string &str) {
	str  += " and ponies";
}

void	byConstRef(string const &str) {
	std::cout << str << std::endl;
}

int	main() {
	string str = "i like butterflies";

	std::cout << str << std::endl;
	byPtr(&str);
	byConstPtr(&str);

	str = "i like others";
	std::cout << str << std::endl;
	byRef(str);
	byConstRef(str);

	return 0;
}

