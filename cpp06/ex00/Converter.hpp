/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 12:49:58 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/11/11 20:06:28 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTER_HPP
# define CONVERTER_HPP

# include <iostream>
# include <string>
# include <iomanip>
# include <climits>

using std::string;

class Converter {
	
	private:
		Converter();
		Converter(Converter const &src);
		~Converter();
		Converter &operator=(Converter const &src);
	
	public:
		static void convert(const string &input);
};

#endif