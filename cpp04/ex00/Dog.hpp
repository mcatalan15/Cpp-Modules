/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 17:45:10 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/09/23 11:38:14 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog: public Animal {

	public:
		Dog();
		Dog(const std::string &type);
		Dog(const Dog &src);
		~Dog();

		Dog &operator=(const Dog &src);

		void makeSound() const;
};

#endif
