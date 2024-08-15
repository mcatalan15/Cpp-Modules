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
