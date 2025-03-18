#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <fstream>
#include <stdexcept>
#include <cstdlib> // For std::atof
#include <sstream> // Include stringstream header

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
