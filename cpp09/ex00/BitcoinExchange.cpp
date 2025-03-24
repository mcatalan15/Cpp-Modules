#include "BitcoinExchange.hpp"

// Constructor sets the input and the database map, also executes the Bitcoin value calculation
BitcoinExchange::BitcoinExchange(string input, std::map<std::string, double> databaseMap) : _database(databaseMap), _input(input) { showBitcoinValue(); }

// Copy constructor
BitcoinExchange::BitcoinExchange(const BitcoinExchange & cpy) { *this = cpy; }

// Destructor
BitcoinExchange::~BitcoinExchange() {}

// Assignment operator
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange & cpy) {
	if (this != &cpy) {
		this->_input = cpy.getInput();
		this->_database = cpy.getDatabaseMap();
	}
	return (*this);
}	

// Getter for input
string BitcoinExchange::getInput() const { return (this->_input); }

// Getter for database map
std::map<std::string, double> BitcoinExchange::getDatabaseMap() const { return (this->_database); }

// checker if string is integer
bool	isStrInt(string str) {
	for (unsigned int i = 0; i < str.length(); i++) {
		if (str[i] < '0' || str[i] > '9')
			return (false);
	}
	return (true);
}

// checker if string is double
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

// transalate string to integer
int stringToInt(const std::string& str) {
	std::stringstream ss(str);
	int value;
	ss >> value;
	if (ss.fail() || !ss.eof()) {
		throw std::invalid_argument("Invalid integer format: " + str);
	}
	return value;
}

// transalate string to double
double stringToDouble(const std::string& str) {
	std::stringstream ss(str);
	double value;
	ss >> value;
	if (ss.fail() || !ss.eof()) {
		throw std::invalid_argument("Invalid double format: " + str);
	}
	return value;
}

// Remove spaces from str
string	removeSpaces(string line) {
	size_t start = line.find_first_not_of(' ');
	if (start == string::npos)
		return ("");
	size_t end = line.find_last_not_of(' ');
	return (line.substr(start, end - start + 1));
}

// Checks if date is valid
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

// Gets the date through the checkers
string getDate(string input) {
	string line = removeSpaces(input);
	if (line.size() < 10)
		throw std::out_of_range("bad input");

	size_t delimiterPos = line.find(',');
	if (delimiterPos == string::npos) {
		delimiterPos = line.find('|');
		if (delimiterPos == string::npos)
			throw std::invalid_argument("bad input: missing delimiter (',' or '|')");
	}

	string datePart = line.substr(0, delimiterPos);
	datePart = removeSpaces(datePart);

	if (datePart.size() != 10 || datePart[4] != '-' || datePart[7] != '-')
		throw std::invalid_argument("bad input: invalid date format");

	string y = datePart.substr(0, 4);
	string m = datePart.substr(5, 2);
	string d = datePart.substr(8, 2);

	if (!isStrInt(y) || !isStrInt(m) || !isStrInt(d))
		throw std::invalid_argument("bad input: invalid date");

	checkExistingDate(stringToInt(y), stringToInt(m), stringToInt(d));
	return datePart;
}

// Checker the decimal number
void check_decimals(const std::string& line) {
	size_t dot_pos = line.find('.');
	if (dot_pos != std::string::npos) {
		if (dot_pos == 0 || !isdigit(line[dot_pos - 1]))
			throw std::invalid_argument("Invalid decimal number: no digit before the dot.");
		if (dot_pos == line.length() - 1 || !isdigit(line[dot_pos + 1]))
			throw std::invalid_argument("Invalid decimal number: no digit after the dot.");
	}
}

// Getter of quantity
double getQuantity(string input) {
	// Check for either ',' or '|' as the delimiter
	size_t delimiterPos = input.find(',');
	if (delimiterPos == string::npos) {
		delimiterPos = input.find('|');
		if (delimiterPos == string::npos)
			throw std::invalid_argument("bad input: missing delimiter (',' or '|')");
	}

	string quantityStr = removeSpaces(input.substr(delimiterPos + 1));
	check_decimals(quantityStr);

	double quantity = stringToDouble(quantityStr);
	if (quantity < 0)
		throw std::out_of_range("not a positive number.");
	if (quantity > 1000)
		throw std::out_of_range("too large number.");
	if (!isStrDouble(quantityStr))
		throw std::invalid_argument("bad input => " + input);

	return quantity;
}

// Search function
void BitcoinExchange::searchInDatabase(std::string date, double quantity) {
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

// Main function that executes the rest of the code
void BitcoinExchange::showBitcoinValue() {
	std::ifstream input(this->_input.c_str());
	if (!input.is_open())
		throw std::invalid_argument("could not open file.");

	std::string line;
	bool isFirstLine = true; // Flag to skip the header line
	while (std::getline(input, line)) {
		if (isFirstLine) {
			isFirstLine = false;
			continue; // Skip the header line
		}
		if (line.empty()) // Skip empty lines
			continue;
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
	}
	input.close();
}
