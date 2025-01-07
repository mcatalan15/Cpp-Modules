/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 11:34:32 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/12/30 11:52:08 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

// Default constructor Inherits from std::stack
template<typename T>
MutantStack<T>::MutantStack() : std::stack<T>() {}

// Copy constructor
template <typename T>
MutantStack<T>::MutantStack(const MutantStack &src) : std::stack<T>(src) {}

// Destructor
template<typename T>
MutantStack<T>::~MutantStack() {}

// Assigment Operator '='
template<typename T>
MutantStack<T> & MutantStack<T>::operator=(const MutantStack<T> &src){
    return (std::stack<T>::operator=(src));
}

/*
	Returns the iterator pointing the begining.
	Allows iteration through the stack's elements in ascending order.
*/
template<typename T>
typename MutantStack<T>::iterator   MutantStack<T>::begin() {
    return (this->c.begin());
}

/*
	Returns the iterator pointing past the last element.
	Used for making the end of the iteration range.
*/
template <typename T>
typename MutantStack<T>::iterator   MutantStack<T>::end() {
    return (this->c.end());
}

