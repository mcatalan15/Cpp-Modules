/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 07:49:43 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/08/16 07:49:44 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Zombie.hpp"

Zombie::Zombie(std::string name) {
    this->_name = name;
}

Zombie::~Zombie(void) {
    std::cout << this->_name << " has been destroyed." << std::endl;
}

void Zombie::announce(void) const {
    std::cout << this->_name << " BraiiiiiiinnzzzZ..." << std::endl;
}

