/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 07:50:36 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/08/16 07:50:37 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H

# include "Contact.hpp"

class	PhoneBook{

	public:
		PhoneBook();
		~PhoneBook();
		void	addContact();
		void	searchContact();
		void	showContact();
		int	saveContact(int	nb);
	
	private:
		Contact _contact[8];
		int	_lastIx;
		int	_size;
};

#endif
