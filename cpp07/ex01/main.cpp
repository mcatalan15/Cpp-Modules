/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 20:16:04 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/12/13 20:16:05 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

using std::string;

/*
	This function is used to print the elements of the array.
*/
int main() {
   int arr[] = {5, 3, -4, 1, 546, 89};
   ::iter(arr, 6, &print);

   string str[4]= {"hi", "hola", "hallo", "hey"};
   ::iter(str, 4, &print);
}
