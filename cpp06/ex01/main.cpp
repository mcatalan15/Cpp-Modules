/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:36:55 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/11/12 10:38:53 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

int main() {
    Data* data = new Data;
    data->i = 16;
    data->info = "hola";

    uintptr_t serial = Serializer::serialize(data);
    std::cout << "Data pointer: " << data << " | int: " << data->i << " | info: " << data->info <<std::endl;
    Data *newData = Serializer::deserialize(serial);
    std::cout << "Data pointer: " << newData << " | int: " << newData->i << " | info: " << newData->info << std::endl;

    delete data;

    return 0;
}
