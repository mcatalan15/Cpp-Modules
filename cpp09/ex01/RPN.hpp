#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>

class RPN {
	public:
		RPN(std::string input);
		RPN(const RPN &src);
		~RPN();
		RPN &operator=(const RPN &src);

		std::stack<double> getStack() const;

		void operateStack(std::string input);

	private:
		std::stack<double> _st;
};

#endif
