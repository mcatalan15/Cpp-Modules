/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 11:34:25 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/12/30 11:56:08 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <iterator>

#define RESET "\033[0m"
#define RED "\033[31m"

/*
	Class that inherits from std::stack.
	Ortodox class
	Allows iteration through elements with the container definition.
	Begin and end methots to access the start adn end iterators of the stack's container.
*/
template <typename T>
class MutantStack : public std::stack<T> {
    public:
        MutantStack();
        MutantStack(const MutantStack &src);
        ~MutantStack();

        MutantStack &operator=(const MutantStack &src);
    
        typedef typename std::stack<T>::container_type::iterator iterator;
        iterator    begin();
        iterator    end();
};

#endif
