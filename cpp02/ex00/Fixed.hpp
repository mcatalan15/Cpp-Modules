#ifndef FIXED_H
# define #FIXED_H

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

