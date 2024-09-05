/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 11:14:33 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/09/05 11:14:34 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

# include <iostream>
# include <cstring>
# include <iomanip>

class	Fixed	{

	public:
		Fixed();
		Fixed(Fixed const &src);
		~Fixed();

		Fixed &operator=(Fixed const &rhs);

		int	getRawBits() const;
		void	setRawBits(int const raw);

	private:
		int num;
		static int const bits = 8;
};

# endif 

