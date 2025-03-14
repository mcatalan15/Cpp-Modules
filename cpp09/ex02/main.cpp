/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 16:39:11 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/12/28 19:48:57 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/*
	main function for PmergeMe.
	Checks the number of arguments and calls the merge_process function.
	Prints the time taken to process the data.
	if the number of arguments is invalid, it throws an error.
*/
int main(int argc, char **argv) {
    try {
        if (argc < 2 || argc > 10000)
            throw PmergeMe::errorException();
        PmergeMe    merge(&argv[1]);
        merge.merge_process();
        merge.print_time();
    }
    catch (PmergeMe::errorException &e) {
        std::cout << e.what() << std::endl;
    }
}
