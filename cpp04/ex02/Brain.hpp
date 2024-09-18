/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 18:28:52 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/09/17 16:32:28 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain {	
	public:
		Brain();
		Brain(const Brain &src);
		~Brain();

		Brain &operator=(const Brain &src);
		
		std::string getIdea() const;
		void		setIdea(const std::string &idea);
		void		printIdeas();

	private:
		std::string	_ideas[100];
		int			_index;
};

#endif