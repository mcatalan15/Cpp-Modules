/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 10:48:01 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/12/16 12:21:50 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <fstream>
#include <stdexcept>

using std::string;

class BitcoinExchange {
	private:
		std::map<std::string, double> _database;
		std::string _input;

	public:
		BitcoinExchange(string input, std::map<std::string, double> databaseMap);
		BitcoinExchange(const BitcoinExchange &cpy);
		~BitcoinExchange();

		BitcoinExchange &operator=(const BitcoinExchange &cpy);
		
		string getInput() const;
		std::map<std::string, double> getDatabaseMap() const;
		void	showBitcoinValue();
		void	searchInDatabase(std::string date, double quantity);
};

#endif
