/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 20:15:45 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/12/13 20:15:46 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>
# include <vector>
# include <deque>
# include <list>

# define RESET "\033[0m"
# define RED "\033[31m"
# define GREEN "\033[32m"

/*
	This template function will search for a number in a container.
	If the number is found, it will return an iterator to the number.
	to find the number we use the std::find function sendinf the container
	and the number to find.
	If the number is not found, it will throw an exception.
*/
template <typename T>
typename T::const_iterator  easyfind(const T& cont, int nb) {
    typename T::const_iterator it = std::find(cont.begin(), cont.end(), nb);
    if (it != cont.end())
        return it;
    else
        throw std::logic_error("Number not found");
}

#endif
