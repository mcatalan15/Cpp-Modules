/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 17:36:28 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/09/13 18:28:07 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <cstring>
#include <iomanip>
#include "Brain.hpp"

class Animal {
	
	protected:
		std::string _type;
	
	public:
		Animal();
		Animal(const std::string &type);
		Animal(const Animal &src);
		virtual ~Animal();
	
		Animal &operator=(const Animal &src);
		
		std::string getType() const;
		void		setType(const std::string &type);
		
		virtual void makeSound() const;
};

#endif
