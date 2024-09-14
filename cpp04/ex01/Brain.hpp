/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 18:28:52 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/09/13 18:32:03 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain {
	
	private:
		std::string	_ideas[100];
		int			_index;
	
	public:
		Brain();
		Brain(const Brain &src);
		~Brain();

		Brain &operator=(const Brain &src);
		
		std::string getIdea() const;
		void		setIdea(const std::string &idea);
		void		printIdeas();
};

#endif