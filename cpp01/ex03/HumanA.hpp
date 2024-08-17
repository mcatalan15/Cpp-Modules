/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 08:02:57 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/08/16 08:02:58 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef HUMANA_H_
# define HUMANA_H_
# include "Weapon.hpp"

class	HumanA {
	
	public:
		HumanA(std::string name, Weapon &weapon);
		~HumanA();

		void	attack();
	private:
		std::string	_name;
		Weapon		&_weaponA;
};

#endif
