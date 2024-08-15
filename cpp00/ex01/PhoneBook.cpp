#include "PhoneBook.hpp"

PhoneBook::PhoneBook()	{
	this->_lastIx = -1;
	this->_size = 0;
}

PhoneBook::~PhoneBook()	{
}

std::string	inputOption(std::string option)	{

	std::string	input;

	std::cout << option << ": ";
	if (!std::getline(std::cin, input))
		return ("");
	while (input == "" || std::isspace(input[0]))	{
		std::cout << "Input incorrect" << std::endl;
		std::cout << option << ":";
		if (!std::getline(std::cin, input))
			return ("");
	}
	return input;
}

int	PhoneBook::saveContact(int num)	{

	Contact	*p;
	std::string	input;
	p = &this->_contact[num];

	input = inputOption("First Name");
	if (input == "")
		return 1;
	p->setFirstName(input);
	input = inputOption("Last Name");
	if (input == "")
		return 1;
	p->setLastName(input);
	input = inputOption("Nickname");
	if (input == "")
		return 1;
	p->setNickName(input);
	input = inputOption("Phone Number");
	if (input == "")
		return 1;
	p->setPhoneNumber(input);
	input = inputOption("Darkest Secret");
	if (input == "")
		return 1;
	p->setDarkestSecret(input);
	return 0;
}

void	PhoneBook::addContact()	{
	this->_lastIx = (this->_lastIx == 7) ? 0 : this->_lastIx + 1; //if _lastIx is 7 equal to 0 if not increment 1

	Contact::setNb(this->_lastIx); //called Contact.cpp
	if (this->saveContact(this->_lastIx)) //saving the contact
		return ;
	std::cout << "New contact saved!\n" << std::endl;
	if (this->_size < 8)
		this->_size += 1;
	return ;
}

void	PhoneBook::showContact()	{

	std::cout << std::setw(10) << "Index" << "|" << std::setw(10) << "First Name" << "|" << std::setw(10) << "Last Name" << "|" << \
		std::setw(10) << "Nickname" << std::endl;
	for (int i = 0; i < this->_size; i++)	{
		std::cout << std::setw(10) << i + 1 << "|";

		if (this->_contact[i].getFirstName().size() > 10)
			std::cout << std::setw(9) << this->_contact[i].getFirstName().substr(0, 9) << "." << "|";
		else
			std::cout << std::setw(9) << this->_contact[i].getFirstName() << "|";
		if (this->_contact[i].getLastName().size() > 10)
			std::cout << std::setw(9) << this->_contact[i].getLastName().substr(0, 9) << "." << "|";
		else
			std::cout << std::setw(9) << this->_contact[i].getLastName() << "|";
		if (this->_contact[i].getNickName().size() > 10)
			std::cout << std::setw(9) << this->_contact[i].getNickName().substr(0, 9) << "." << std::endl;
		else
			std::cout << std::setw(9) << this->_contact[i].getNickName() << std::endl;
	}
}

void	PhoneBook::searchContact()	{

	std::string	input;
	int		index = 0;

	if(this->_size == 0)	{
		std::cout << "Phonebook is empty\n" << std::endl;
		return ;
	}
	this->showContact();
	std::cout << "Enter the index that you want to display" << std::endl;
	std::cout << ">> ";
	if(!std::getline(std::cin, input))
		return ;
	else if (input.length() != 1 || (input[0] - 49) < 0 || (input[0] - 48) > this->_size)
		return std::cout << "Invalid index\n" <<std::endl, void(); //se puede hacer?
	index = input[0] - '0' - 1;

	std::cout << std::setw(10) << "Index" << "|" << \
		std::setw(10) << "First Name" << "|" << \
		std::setw(10) << "Last Name" << "|" << \
		std::setw(10) << "Nickname" << "|" << \
		std::setw(10) << "Phone Number" << "|" << \
		std::setw(10) << "Darkest Secret" << "|" << \
	std::cout << std::setw(10) << index + 1 << "|" <<
	std::setw(10) << this->_contact[index].getFirstName() << "|" <<
	std::setw(10) << this->_contact[index].getLastName() << "|" <<
	std::setw(10) << this->_contact[index].getNickName() << "|" <<
	std::setw(10) << this->_contact[index].getPhoneNumber() << "|" <<
	std::setw(10) << this->_contact[index].getDarkestSecret() <<
	std::endl << std::endl;
}

