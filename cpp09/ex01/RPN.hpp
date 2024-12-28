/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:17:40 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/12/19 12:47:28 by mcatalan@st      ###   ########.fr       */
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
