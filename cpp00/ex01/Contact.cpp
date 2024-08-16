/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 07:50:25 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/08/16 07:50:26 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

int	Contact::_nContact = 0;

Contact::Contact()	{}

Contact::~Contact()	{}

int	Contact::getNb() { return (Contact::_nContact);}

void	Contact:: setNb(int i) { Contact::_nContact = i;}

std::string Contact::getFirstName() { return (_firstName);}
void	Contact::setFirstName(std::string str) { this->_firstName = str;}

std::string Contact::getLastName(){return (_lastName);}
void	Contact::setLastName(std::string str) { this->_lastName = str;}

std::string Contact::getNickName(){return (_nickName);}
void	Contact::setNickName(std::string str) { this->_nickName = str;}

std::string Contact::getPhoneNumber(){return (_phoneNumber);}
void	Contact::setPhoneNumber(std::string str) { this->_phoneNumber = str;}

std::string Contact::getDarkestSecret(){return (_darkestSecret);}
void	Contact::setDarkestSecret(std::string str) { this->_darkestSecret = str;}

