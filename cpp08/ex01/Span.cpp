/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 20:18:27 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/12/13 20:25:25 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

// Constructor
Span::Span(unsigned int n) : _size(n) {}

// Copy constructor
Span::Span(const Span &src) { *this = src; }

// Destructor
Span::~Span() {}

// Operator '=' overload
Span &Span::operator=(const Span &src) {
    if (this != &src) {
        this ->_size = src.getSize();
        this->_span = src.getSpan();
    }
    return (*this);
}

// Getters
// Getter for _span
std::multiset<int> Span::getSpan() const { return _span; }

// Getter for _size
unsigned int    Span::getSize()const { return _size; }

// Functions
// Add a number to the span checking if it is full
void Span::addNumber(int nb) {
	if (this->_span.size() < _size)
		this->_span.insert(nb);
	else
		throw std::runtime_error("Span is full.");
}

// Add a range of numbers to the span using random numbers for the size of the span
void    Span::addRangeNumbers() {
    srand(time(NULL));
    for (unsigned int i = 0; i < _size; i++) {
        this->_span.insert(rand() % _size + 1);
    }
}

/*
	This functions calculates the shortest span between two numbers in the span.
	We iterate through the span and calculate the difference between each number.
	We store the smallest difference in the variable diff.
*/
unsigned int    Span::shortestSpan() {
    if (this->_span.empty() || this->_span.size() < 2)
        throw std::runtime_error("Span has less than 2 numbers.");

    std::multiset<int>::iterator    it = ++(this->_span.begin());
    std::multiset<int>::iterator    prev = this->_span.begin();
    unsigned int diff = *(--(this->_span.end())) - *it;

    for (; it != this->_span.end(); it++) {
        if ((unsigned int)(*it - *prev) < diff)
            diff = *it - *prev;
        prev++;
    }
    return diff;
}

/*
	This function calculates the longest span between two numbers in the span.
	We return the difference between the last and first element in the span.
*/
unsigned int Span::longestSpan() {
    if (this->_span.empty() || this->_span.size() < 2)
        throw std::runtime_error("Span has less than 2 numbers.");
    else {
        std::multiset<int>::iterator first = this->_span.begin();
        std::multiset<int>::iterator last = this->_span.end();
        last--;
        return (*last - *first);
    }
}

// Print the span iterating through it
void Span::printSpan() const {
	for (std::multiset<int>::const_iterator it = _span.begin(); it != _span.end(); ++it) {
        std::cout << "number: " << *it << std::endl;
    }
}
