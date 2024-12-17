/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 10:48:05 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/12/17 11:59:40 by mcatalan@st      ###   ########.fr       */
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
			databaseMap.insert(std::make_pair(line.substr(0, line.find(",")), std::stod(line.substr(++posComma))));
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
