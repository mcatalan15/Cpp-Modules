/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 08:03:12 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/08/16 08:03:13 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef WEAPON_H_
# define WEAPON_H_
# include <iostream>
# include <cstring>
# include <iomanip>

class	Weapon	{

	public:
		Weapon(std::string type);
		//Weapon();
		~Weapon();

	//	Weapon(std::string type);
		std::string const getType();
		void	setType(std::string type);

	private:
		std::string _type;
};

#endif
