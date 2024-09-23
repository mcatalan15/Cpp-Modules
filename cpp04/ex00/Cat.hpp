/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 17:42:37 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/09/23 11:34:47 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat: public Animal {
	
	public:
		Cat();
		Cat(const std::string &type);
		Cat(const Cat &src);
		~Cat();

		Cat &operator=(const Cat &src);

		void makeSound();
		void makeSound() const;
};

#endif