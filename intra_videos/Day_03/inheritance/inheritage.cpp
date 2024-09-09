#include <string>

class Cat {

	private:
		int	numberOfLegs;
	
	public:
		Cat();
		Cat(Cat const &);
		Cat &operator=(Cat const &);
		~Cat();

		void	run(int distance);
		void	scornSomeone(std::string const &target);
};

class Pony {

	private:
		int	numOfLegs;

	
};

