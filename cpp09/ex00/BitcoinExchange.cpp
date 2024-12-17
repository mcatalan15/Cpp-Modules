/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 10:48:22 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/12/17 11:16:32 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

using std::string;

BitcoinExchange::BitcoinExchange(string input, std::map<std::string, double> databaseMap) : _database(databaseMap), _input(input) { showBitcoinValue(); }

BitcoinExchange::BitcoinExchange(const BitcoinExchange & cpy) { *this = cpy; }

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange & cpy) {
	if (this != &cpy) {
		this->_input = cpy.getInput();
		this->_database = cpy.getDatabaseMap();
	}
	return (*this);
}	

string BitcoinExchange::getInput() const { return (this->_input); }

std::map<std::string, double> BitcoinExchange::getDatabaseMap() const { return (this->_database); }

bool	isStrInt(string str) {
	for (unsigned int i = 0; i < str.length(); i++) {
		if (str[i] < '0' || str[i] > '9')
			return (false);
	}
	return (true);
}

bool	isStrDouble(string str) {
	bool point = false;
	for (unsigned int i = 0; i < str.length(); i++) {
		if ((str[i] < '0' || str[i] > '9') && str[i] != '.')
			return (false);
		else if (str[i] == '.') {
			if (!point)
				point = true;
			else
				return (false);
		}
	}
	return (true);
}

string	removeSpaces(string line) {
	size_t start = line.find_first_not_of(' ');
	if (start == string::npos)
		return ("");
	size_t end = line.find_last_not_of(' ');
	return (line.substr(start, end - start + 1));
}

void checkExistingDate(int y, int m, int d) {
	if (m < 1 || m > 12 || d < 1 || d > 31)
		throw std::out_of_range("Invalid date");
	if (d > 30 && (m == 4 || m == 6 || m == 9 || m == 11))
		throw std::out_of_range("Invalid date");
	if (m == 2 && d > 28) {
		if (d > 29)
			throw std::out_of_range("Invalid date");
		if (y % 4 != 0 || y % 100 == 0 || y % 400 != 0)
			throw std::out_of_range("Invalid date");
	}
}

string	getDate(string input) {
	string line = removeSpaces(input);
	if (line.size() < 14)
		throw std::out_of_range("bad input");
	string y = line.substr(0, 4);
	string m = line.substr(5, 2);
	string d = line.substr(8, 2);
	if (!isStrInt(y) || !isStrInt(m) || !isStrInt(d) || line[4] != '-' || line[7] != '-')
		throw std::invalid_argument("bad input");
	line = removeSpaces(line.substr(10));
	if (line[0] != '|')
		throw std::invalid_argument("bad input");
	checkExistingDate(std::stoi(y), std::stoi(m), std::stoi(d));
	string date = y + "-" + m + "-" + d;
	return date;
}

double	getQuantity(string input) {
	size_t bar = input.find("|");
	std::string line = removeSpaces(input.substr(++bar));
	double quantity = std::stod(line);
	if (quantity < 0)
		throw std::out_of_range("not a positive number.");
	if (quantity > 1000)
		throw std::out_of_range("too large number.");
	if (!isStrDouble(line))
		throw std::invalid_argument("bad input => " + input);
	return (quantity);
}

void BitcoinExchange::searchInDatabase(std::string date, double quantity)
{
	std::map<std::string, double>::iterator it = _database.find(date);
	if (it == _database.end()) {
		if (std::strcmp(date.c_str(), _database.begin()->first.c_str()) < 0)
			throw std::out_of_range("invalid date, too old.");
		else {
			for (it = this->_database.begin(); it != _database.end(); ++it) {
				if (std::strcmp(it->first.c_str(), date.c_str()) > 0) {
					--it;
					break;
				}
			}
			if (it == _database.end())
				--it;
		}
	}
	std::cout << date << " => " << quantity << " = " << quantity * it->second << std::endl;
}

void BitcoinExchange::showBitcoinValue() {
	std::ifstream input(this->_input);
	if (!input.is_open())
		throw std::invalid_argument("could not open file.");

	std::string line;
	int index = 0;
	while (std::getline(input, line)) {
		if (index > 0) {
			try {
				std::string date = getDate(line);
				double quantity = getQuantity(line);
				searchInDatabase(date, quantity);
			}
			catch (std::invalid_argument e) {
				std::cout << "Error: " << e.what() << std::endl;
			}
			catch (const std::out_of_range &e) {
				std::cout << "Error: " << e.what() << std::endl;
			}
		}
		index++;
	}
	input.close();
}
