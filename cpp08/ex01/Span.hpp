#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <set>
#include <cstdlib>
#include <ctime>

#define RESET "\033[0m"
#define RED "\033[31m"

/*
	This class creates a Span of numbers.
	private:
		_multiset<int>	_span: A multiset to store the numbers.
		unsigned int	_size: The size of the span.
	public:
		Orthodox canonical form
		Getters
		Functions
*/
class Span {
    private:
        std::multiset<int>  _span;
        unsigned int        _size;
    public:
        Span(unsigned int n);
        Span(const Span &src);
        ~Span();

        Span& operator=(const Span &src);

        std::multiset<int>      getSpan() const;
        unsigned int            getSize() const;

        void    addNumber(int nb);
        void    addRangeNumbers();
        unsigned    int    shortestSpan();
        unsigned    int 	longestSpan();
        void    printSpan() const;
};

#endif // !SPAN_HPP
