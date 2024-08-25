/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 07:50:36 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/08/21 11:59:46 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H

# include "Contact.hpp"

/*
    Contact.hpp to have the includes.
*/

class	PhoneBook{

	public:
		PhoneBook();
		~PhoneBook();
		void	addContact();
		void	searchContact();
		int	saveContact(int	nb);
	
	private:
		Contact contact[8];
		int	lastIndex;
		int	size;
};

#endif
