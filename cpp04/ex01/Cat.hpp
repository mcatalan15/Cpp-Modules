/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 17:42:37 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/09/13 18:33:22 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat: public Animal {
	
	private:
		Brain *_brain;
	public:
		Cat();
		Cat(const Cat &src);
		~Cat();

		Cat &operator=(const Cat &src);

		Brain *getBrain() const;
		void setBrain(Brain *brain);

		void makeSound();
		void makeSound() const;
};

#endif