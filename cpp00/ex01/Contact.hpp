/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 07:50:28 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/09/03 18:35:29 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_H
# define CONTACT_CLASS_H

# include <iostream>
# include <cstring>
# include <iomanip>

/*
	Iosmanip for the manipulation of the input/output. Useful for the SEARCH option.

	This Class declaration has public (accessible from anywhere) and private
	(Accessible only with in the class).
	*Public:
		- Constructor and deconstructor.
		- Functions that get private variables values anywhere (where the variables
			are not accessible).
	*Private:
		- All the variables.
		- Static numContact to ensure there's only one copy of this value.
*/

class	Contact	{

	public:
		Contact();
		~Contact();

		void	setFirstName(std::string str);
		void	setLastName(std::string str);
		void	setNickName(std::string str);
		bool	setPhoneNumber(std::string str);
		void	setDarkestSecret(std::string str);
		static	void	setNumContact(int n);
		
		static	int	getNumContact();
		std::string	getFirstName();
		std::string	getLastName();
		std::string	getNickName();
		std::string	getPhoneNumber();
		std::string	getDarkestSecret();

	private:
		std::string	firstName;
		std::string	lastName;
		std::string	nickName;
		std::string	phoneNum;
		std::string	darkestSecret;
		static	int	numContact;	
};

#endif
