/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 08:02:29 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/08/16 08:02:30 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
    Zombie *zombiePtr;
    
    int N = 15;
    zombiePtr = zombieHorde(N, "Roberto");
    for (int i = 0; i < N; i++) {
        std::cout << "Zombie num " << i+1 << " announcement:" << std::endl;
        zombiePtr[i].announce();
    }
    
    delete[] zombiePtr;
    
    return 0;
}
