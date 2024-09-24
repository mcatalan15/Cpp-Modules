/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 17:36:28 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/09/24 21:17:13 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <cstring>
#include <iomanip>
#include "Brain.hpp"

/*
	In this class we can see the use of abstract classes.
	An abstract class is a class that has at least one pure virtual function.
	A pure virtual function is a function that has no implementation.
	We can declare a pure virtual function by adding the = 0 at the end of the function declaration.
	
	We can't create an object of an abstract class.
	We can create a pointer to an abstract class.
	We can create a reference to an abstract class.
*/

class AAnimal {

	protected:
		std::string _type;
	
	public:
		AAnimal();
		AAnimal(const std::string &type);
		AAnimal(const AAnimal &src);
		virtual ~AAnimal();
	
		AAnimal &operator=(const AAnimal &src);
		
		std::string getType() const;
		void		setType(const std::string &type);
		virtual	void makeSound() const = 0;
};

#endif
