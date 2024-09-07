/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 11:14:33 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/09/06 16:49:53 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

# include <iostream>
# include <cstring>
# include <iomanip>
# include <cmath>

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
		Fixed(int const numI);
		Fixed(float const numF);
		~Fixed();

		Fixed &operator=(Fixed const &rhs);

		// Comparison operators
		bool operator>(Fixed const &rhs) const;
		bool operator<(Fixed const &rhs) const;
		bool operator>=(Fixed const &rhs) const;
		bool operator<=(Fixed const &rhs) const;
		bool operator==(Fixed const &rhs) const;
		bool operator!=(Fixed const &rhs) const;
		
		// Arithmetic operators
		float operator+(Fixed const &rhs) const;
		float operator-(Fixed const &rhs) const;
		float operator*(Fixed const &rhs) const;
		float operator/(Fixed const &rhs) const;

		// Increment & decrement operators
		// Preoperators
		// Postoperators
		Fixed operator++(void);
		Fixed operator++(int);
		Fixed operator--(void);
		Fixed operator--(int);
		

		// MAX & MIN operators
		// Operator min
		static const Fixed &min(Fixed const &first, Fixed const &second);
		static Fixed &min(Fixed &first, Fixed &second);
		// Operator max
		static const Fixed &max(Fixed const &first, Fixed const &second);
		static Fixed &max(Fixed &first, Fixed &second);

		int	toInt(void) const;
		float toFloat(void) const;

		int	getRawBits(void) const;
		void	setRawBits(int const raw);

	private:
		int fPointValue;
		static int const fBits = 8;
};

std::ostream & operator<<(std::ostream & out, Fixed & rhs);
std::ostream & operator<<(std::ostream & out, Fixed const & rhs);

# endif 
