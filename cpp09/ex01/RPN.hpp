/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 12:11:20 by mcatalan@st       #+#    #+#             */
/*   Updated: 2025/01/10 12:11:23 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>

class RPN
{

public:
	RPN(std::string input);
	RPN(const RPN &src);
	~RPN();
	RPN &operator=(const RPN &src);

	std::stack<double> getStack() const;

	void operateStack(std::string input);

private:
	std::stack<double> _st;
};

#endif
