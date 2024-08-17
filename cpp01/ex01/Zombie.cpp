/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 08:02:35 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/08/16 08:02:36 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(){}

Zombie::Zombie(std::string name) {
    this->_name = name;
}

Zombie::~Zombie(void) {
    std::cout << this->_name << " has been destroyed." << std::endl;
}

void    Zombie::setName(std::string name) {
    this->_name = name;
}

void Zombie::announce() {
    std::cout << this->_name << " BraiiiiiiinnzzzZ..." << std::endl;
}