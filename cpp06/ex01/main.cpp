/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:36:55 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/12/11 12:46:03 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

/*
	This main function creates a Data pointer and initializes it with an integer and a string.
	Then it serializes the pointer and prints the data. After that, it deserializes the pointer
	and prints the data again.

	Serialization:
	Process of converting an object, data structure or memory state into
	a format that can be stored, trasnferred or reconstructed later.
*/
int main() {
    Data* data = new Data;
    data->i = 16;
    data->info = "hola";

    uintptr_t serial = Serializer::serialize(data);
    std::cout << "Data pointer: " << data << " | int: " << data->i << " | info: " << data->info << " | serialize num: " << serial <<std::endl;
    Data *newData = Serializer::deserialize(serial);
    std::cout << "Data pointer: " << newData << " | int: " << newData->i << " | info: " << newData->info << " | serialize num: " << serial << std::endl;

    delete data;

    return 0;
}
