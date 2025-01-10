/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 11:33:47 by mcatalan@st       #+#    #+#             */
/*   Updated: 2025/01/10 12:09:19 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

std::map<std::string, double> saveDatabaseMap() {
	std::ifstream database("data.csv");
	if (!database.is_open())
		throw std::invalid_argument("could not open file.");

	std::map<std::string, double> databaseMap;
	std::string line;
	int index = 0;

	while (std::getline(database, line)) {
		if (index > 0) {
			size_t posComma = line.find(",");
			if (posComma == std::string::npos)
				throw std::invalid_argument("Invalid format in database file.");
			std::string date = line.substr(0, posComma);
			std::string valueStr = line.substr(posComma + 1);
			std::stringstream valueStream(valueStr);

			double value;
			valueStream >> value;
			if (valueStream.fail())
				throw std::invalid_argument("Invalid numeric value in database file.");
			databaseMap.insert(std::make_pair(date, value));
		}
		index++;
	}
	return databaseMap;
}

int	main(int argc, char **argv) {
	try {
		if (argc != 2)
			throw std::invalid_argument("could not open file.");
		std::map<std::string, double> databaseMap = saveDatabaseMap();
		BitcoinExchange bitcoinEchange(argv[1], databaseMap);
	} catch (std::invalid_argument e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
	return 0;
}
