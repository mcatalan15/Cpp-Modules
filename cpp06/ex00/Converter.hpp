/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 11:16:02 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/12/09 11:25:47 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTER_H
# define CONVERTER_H

# include <iostream>
# include <cstdlib>
# include <iomanip>
# include <climits>
# include <limits>

/*
	Define the int values for each type.
*/

# define	IS_CHAR		0;
# define	IS_INT		1;
# define	IS_FLOAT	2;
# define	IS_DOUBLE	3;
# define	IS_ERROR	4;

/*
	Define Scalar converter class.
	private:
		- Constructor
		- Copy Constructor
		- Operator overload
		- Destructor
	public:
		- detectType
		- printCastFromChar
		- printCastFromInt
		- printCastFromFloat
		- printCastFromDouble
		- convert
		- InvalidFormat

	why the privates? In this specific task, the class is not meant to be instantiated.
	The only public method is the static convert method that we we'll call in the main
	also the exception class is public because we need to catch it in the main.
*/

class  ScalarConverter
{
	private:
		ScalarConverter(void);
		ScalarConverter(ScalarConverter const & source);
		ScalarConverter & operator=(ScalarConverter const & source);
		~ScalarConverter(void);
		
		static int	detectType(std::string str);
		static void	printCastFromChar(std::string str);
		static void	printCastFromInt(std::string str);
		static void	printCastFromFloat(std::string str);
		static void	printCastFromDouble(std::string str);
		
	public:
		static void convert(std::string const str);
		class InvalidFormat: public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

#endif
