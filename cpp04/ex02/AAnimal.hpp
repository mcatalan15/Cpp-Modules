/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 17:36:28 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/09/17 16:31:33 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <cstring>
#include <iomanip>
#include "Brain.hpp"

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
};

#endif
