/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 07:50:36 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/09/04 18:00:22 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H

# include "Contact.hpp"

/*
	This class declaration has public (accessible from anywhere) and private
	(Accessible only with in the class).
	*Public:
		- Constructor and deconstructor.
		- Functions that add a contact to the phonebook.
		- Functions that search a contact in the phonebook.
		- Function that saves a contact in the phonebook.
	*Private:
		- An array of contacts.
		- The last index of the phonebook.
		- The size of the phonebook.
*/

class	PhoneBook{

	public:
		PhoneBook();
		~PhoneBook();
		void	addContact();
		void	searchContact();
		int	saveContact(int	NumContact);
		bool	phoneNumberFilter(std::string str);
	
	private:
		Contact contact[8];
		int	lastIndex;
		int	size;
};

#endif
