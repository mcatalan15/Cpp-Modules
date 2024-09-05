/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 11:14:33 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/09/05 19:14:50 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

# include <iostream>
# include <cstring>
# include <iomanip>

/*
	Ortodox Canonical Form (OCF)
	- Default constructor: Fixed();
	- Copy constructor: Fixed(Fixed const &src);
	- Destructor: ~Fixed();
	- Copy assignment operator: Fixed &operator=(Fixed const &rhs);

	*public:
		- getRawBits(void) const; //Returns the raw value of the fixed point value.
		- setRawBits(int const raw); //Sets the raw value of the fixed point value.
	*private:
		- int num; //The fixed point value.
		- static int const bits = 8; //The number of fractional bits.
*/

class	Fixed	{

	public:
		Fixed();
		Fixed(Fixed const &src);
		~Fixed();

		Fixed &operator=(Fixed const &rhs);

		int	getRawBits(void) const;
		void	setRawBits(int const raw);

	private:
		int num;
		static int const bits = 8;
};

# endif 
