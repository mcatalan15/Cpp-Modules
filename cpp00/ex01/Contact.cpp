/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 07:50:25 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/10/24 19:21:31 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

using string;

//Initialize numContact var to 0
int	Contact::numContact = 0;

//Constructor
Contact::Contact()	{}

//Deconstructor
Contact::~Contact()	{}

//Get functions to return all the variables values on the Contact class
int	Contact::getNumContact() { return (Contact::numContact);}

string Contact::getFirstName() { return (firstName);}

string Contact::getLastName(){return (lastName);}

string Contact::getNickName(){return (nickName);}

string Contact::getPhoneNumber(){return (phoneNum);}

string Contact::getDarkestSecret(){return (darkestSecret);}

//Set functions that with a given value sets the variable to that value
void	Contact:: setNumContact(int i) { Contact::numContact = i;}

void	Contact::setFirstName(string str) { this->firstName = str;}

void	Contact::setLastName(string str) { this->lastName = str;}

void	Contact::setNickName(string str) { this->nickName = str;}

void	Contact::setPhoneNumber(string str) {this->phoneNum = str;}

void	Contact::setDarkestSecret(string str) { this->darkestSecret = str;}
