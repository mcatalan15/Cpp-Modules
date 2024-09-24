/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 17:46:50 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/09/13 17:50:36 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <cstring>
# include <iomanip>

class WrongAnimal {

	protected:
		std::string _type;
	public:
		WrongAnimal();
		WrongAnimal(const std::string type);
		WrongAnimal(const WrongAnimal &src);
		~WrongAnimal();
	
		WrongAnimal &operator=(const WrongAnimal &src);

		std::string getType() const;
		void		setType(const std::string &type);
	
		void makeSound() const;
};

#endif