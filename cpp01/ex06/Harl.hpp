/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 08:03:24 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/09/03 19:36:09 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <cstring>
# include <iomanip>
#include <string>

/*
	This is the Harl class.
	*Public:
		- Constructor and destructor.
		- complain function.
	*Private:
		- debug, info, warning and error functions.
*/

class   Harl {
    public:
        Harl();
        ~Harl();
        
        void    complain( std::string level);
        
    private:
        void debug();
        void info();
        void warning();
        void error();
};

#endif
