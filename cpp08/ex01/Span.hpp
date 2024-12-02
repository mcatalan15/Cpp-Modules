#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <set>

#define RESET "\033[0m"
#define RED "\033[31m"

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
