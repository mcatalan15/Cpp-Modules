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

int stringToInt(const std::string& str) {
	std::stringstream ss(str);
	int value;
	ss >> value;
	if (ss.fail() || !ss.eof()) {
		throw std::invalid_argument("Invalid integer format: " + str);
	}
	return value;
}

double stringToDouble(const std::string& str) {
	std::stringstream ss(str);
	double value;
	ss >> value;
	if (ss.fail() || !ss.eof()) {
		throw std::invalid_argument("Invalid double format: " + str);
	}
	return value;
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
	checkExistingDate(stringToInt(y), stringToInt(m), stringToInt(d));
	string date = y + "-" + m + "-" + d;
	return date;
}

void check_decimals(const std::string& line) {
	size_t dot_pos = line.find('.');
	if (dot_pos != std::string::npos) {
		if (dot_pos == 0 || !isdigit(line[dot_pos - 1]))
			throw std::invalid_argument("Invalid decimal number: no digit before the dot.");
		if (dot_pos == line.length() - 1 || !isdigit(line[dot_pos + 1]))
			throw std::invalid_argument("Invalid decimal number: no digit after the dot.");
	}
}

double	getQuantity(string input) {
	size_t bar = input.find("|");
	std::string line = removeSpaces(input.substr(++bar));
	check_decimals(line);
	double quantity = stringToDouble(line);
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
	std::ifstream input(this->_input.c_str());
	if (!input.is_open())
		throw std::invalid_argument("could not open file.");

	std::string line;
	//int index = 0;
	while (std::getline(input, line)) {
		//if (index > 0) {
			try {
				std::string date = getDate(line);
				double quantity = getQuantity(line);
				searchInDatabase(date, quantity);
			}
			catch (const std::invalid_argument &e) {
				std::cout << "Error: " << e.what() << std::endl;
			}
			catch (const std::out_of_range &e) {
				std::cout << "Error: " << e.what() << std::endl;
			}
			//}
		//index++;
	}
	input.close();
}
