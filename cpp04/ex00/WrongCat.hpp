/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 17:50:46 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/09/13 17:52:50 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal {

	public:
		WrongCat();
		WrongCat(const WrongCat &src);
		~WrongCat();

		WrongCat &operator=(const WrongCat &src);

		void makeSound();
		void makeSound() const;
};

#endif