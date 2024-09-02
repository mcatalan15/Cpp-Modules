/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 07:50:25 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/09/02 05:53:03 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

//Initialize numContact var to 0
int	Contact::numContact = 0;

//Constructor
Contact::Contact()	{}

//Deconstructor
Contact::~Contact()	{}

//Get functions to return all the variables values on the Contact class
int	Contact::getNumContact() { return (Contact::numContact);}

std::string Contact::getFirstName() { return (firstName);}

std::string Contact::getLastName(){return (lastName);}

std::string Contact::getNickName(){return (nickName);}

std::string Contact::getPhoneNumber(){return (phoneNum);}

std::string Contact::getDarkestSecret(){return (darkestSecret);}

//Set functions that with a given value sets the variable to that value
void	Contact:: setNumContact(int i) { Contact::numContact = i;}

void	Contact::setFirstName(std::string str) { this->firstName = str;}

void	Contact::setLastName(std::string str) { this->lastName = str;}

void	Contact::setNickName(std::string str) { this->nickName = str;}

bool	Contact::setPhoneNumber(std::string str) {
	int len = str.length();
	if (len > 9)
		return std::cout << "Phone number too long" << std::endl, false;
	else {
		for (int i = 0; i < len; i++) {
			if (!std::isdigit(str[i]))
				return std::cout << "Phone number must be a number" << std::endl, false;
		}
	}
	this->phoneNum = str;
	return true;
}

void	Contact::setDarkestSecret(std::string str) { this->darkestSecret = str;}
