#include <iostream>
#include <string>

using std::string;

class	Student	{
	private:
		string _login;
	public:
		Student(string const &login) : _login(login){}
		string &getLoginRef() {
			return this->_login;
		}
		string const &getLoginRefConst() const {
			return this->_login;
		}
		string *getLoginPtr() {
			return &(this->_login);
		}
		string const *getLoginPtrConst() const {
			return &(this->_login);
		}
};

int	main() {

	Student	bob = Student("bfubar");
	Student const jim = Student("jfubar");

	std::cout << bob.getLoginRefConst() << " " << jim.getLoginRefConst() << std::endl;
	std::cout << *(bob.getLoginPtrConst())<< " " << *(jim.getLoginPtrConst())<< std::endl;

	bob.getLoginRef() = "bobfubar";
	std::cout << bob.getLoginRefConst() << std::endl;

	*(bob.getLoginPtr()) = "bobfubar";
	std::cout << bob.getLoginRefConst() << std::endl;
}

