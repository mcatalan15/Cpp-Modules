#include "RPN.hpp"

RPN::RPN(std::string input) { operateStack(input); }

RPN::RPN(const RPN &src) { *this = src; }

RPN::~RPN(){}

RPN &RPN::operator=(const RPN &src) {
	if (this != &src)
		this->_st = src.getStack();
	return (*this);
}

// getters
std::stack<double> RPN::getStack() const { return (this->_st); }

// utils
bool isOperator(char c) {
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return (true);
	else
		return (false);
}

// Switch case for each operation
double executeOperation(double a, double b, char op) {
	switch (op) {
	case '+':
		return (a + b);
	case '-':
		return (a - b);
	case '*':
		return (a * b);
	case '/':
		return (a / b);
	}
	return 0;
}

// functions
void RPN::operateStack(std::string input) {
    if (input.empty())
        throw std::invalid_argument("Error");

    size_t i = 0;

    //Handle single number cases
    if (input.size() == 1 && isdigit(input[0])) {
        std::cout << (input[0] - '0') << std::endl;
        return ;
    }
	while (i < input.size()) {
		if (isdigit(input[i]))
			_st.push(input[i] - '0');
		else if (isOperator(input[i]) && (_st.size() > 1)) {
			double a = _st.top();
			_st.pop();
			double b = _st.top();
			_st.pop();
			_st.push(executeOperation(b, a, input[i]));
		}
		else
			throw std::invalid_argument("Error");
		i++;
		if (input[i] != ' ' && i < input.size() - 1)
			throw std::invalid_argument("Error");
		i++;
	}
	if (_st.size() > 1)
		throw std::invalid_argument("Error");
	std::cout <<  _st.top() << std::endl;
}
