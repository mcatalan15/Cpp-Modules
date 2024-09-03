/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 07:50:33 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/09/03 18:16:33 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>

PhoneBook::PhoneBook()	{
	this->lastIndex = -1;
	this->size = 0;
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
	std::string	firstName;
	std::string	lastName;
	std::string	nickName;
	std::string	phoneNumber;
	std::string	darkestSecret;
	p = &this->contact[num];

	input = inputOption("First Name");
	if (input == "")
		return 1;
	firstName = input;
	input = inputOption("Last Name");
	if (input == "")
		return 1;
	lastName = input;
	input = inputOption("Nickname");
	if (input == "")
		return 1;
	nickName = input;
	input = inputOption("Phone Number");
	if (input == "" || !p->setPhoneNumber(input))
		return 1;
	phoneNumber = input;
	input = inputOption("Darkest Secret");
	if (input == "")
		return 1;
	p->setFirstName(input);
	p->setLastName(input);
	p->setNickName(input);
	p->setPhoneNumber(input);
	p->setDarkestSecret(input);
	return 0;
}

void	PhoneBook::addContact()	{
    int tempIndex = (this->lastIndex == 7) ? 0 : this->lastIndex + 1; //if lastIndex is 7 equal to 0 if not increment 1

	Contact::setNumContact(tempIndex); //called Contact.cpp
	if (this->saveContact(tempIndex))	{ //saving the contact if error output + no increment index
		std::cout << "Contact not saved\n" << std::endl;
		return ;
	}
	this->lastIndex = tempIndex;
	std::cout << "New contact saved!\n" << std::endl;
	if (this->size < 8)
		this->size += 1;
	return ;
}

void	PhoneBook::searchContact()	{

	std::string	input;
	int		index = 0;

	if(this->size == 0)	{
		std::cout << "Phonebook is empty\n" << std::endl;
		return ;
	}
	std::cout << std::setw(10) << "Index" << "|" << std::setw(10) << "First Name" << "|" << std::setw(10) << "Last Name" << "|" << \
		std::setw(10) << "Nickname" << std::endl;
	for (int i = 0; i < this->size; i++)	{
		std::cout << std::setw(10) << i + 1 << "|";

		if (this->contact[i].getFirstName().size() > 10)
			std::cout << std::setw(9) << this->contact[i].getFirstName().substr(0, 9) << "." << "|";
		else
			std::cout << std::setw(10) << this->contact[i].getFirstName() << "|";
		if (this->contact[i].getLastName().size() > 10)
			std::cout << std::setw(9) << this->contact[i].getLastName().substr(0, 9) << "." << "|";
		else
			std::cout << std::setw(10) << this->contact[i].getLastName() << "|";
		if (this->contact[i].getNickName().size() > 10)
			std::cout << std::setw(9) << this->contact[i].getNickName().substr(0, 9) << "." << std::endl;
		else
			std::cout << std::setw(10) << this->contact[i].getNickName() << std::endl;
	}
	std::cout << "Enter the index that you want to display" << std::endl;
	std::cout << ">> ";
	if(!std::getline(std::cin, input))
		return ;
	else if (input.length() != 1 || (input[0] - 49) < 0 || (input[0] - 48) > this->size)
		return std::cout << "Invalid index\n" <<std::endl, void();
	index = input[0] - '0' - 1;

	std::cout << "Index: " << index + 1 << std::endl;
	std::cout << "First Name: " << this->contact[index].getFirstName() << std::endl;
	std::cout << "Last Name: " << this->contact[index].getLastName() << std::endl;
	std::cout << "Nickname: " << this->contact[index].getNickName() << std::endl;
	std::cout << "Phone Number: " << this->contact[index].getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << this->contact[index].getDarkestSecret() << std::endl;
}
