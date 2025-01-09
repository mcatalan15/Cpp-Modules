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

// std::map<std::string, double> saveDatabaseMap() {
// 	std::ifstream database("data.csv");
// 	if (!database.is_open())
// 		throw std::invalid_argument("could not open file.");

// 	std::map<std::string, double> databaseMap;
// 	std::string line;
// 	int index = 0;
// 	while (std::getline(database, line)) {
// 		if (index > 0) {
// 			size_t posComma = line.find(",");
// 			databaseMap.insert(std::make_pair(line.substr(0, line.find(",")), std::stringstream(line.substr(++posComma))));
// 		}
// 		index++;
// 	}
// 	return databaseMap;
// }

std::map<std::string, double> saveDatabaseMap() {
    std::ifstream database("data.csv"); // Open the database file
    if (!database.is_open())
        throw std::invalid_argument("could not open file."); // Throw error if file cannot be opened

    std::map<std::string, double> databaseMap; // Map to store the date-value pairs
    std::string line;
    int index = 0;

    while (std::getline(database, line)) { // Read the file line by line
        if (index > 0) { // Skip the first line (header)
            size_t posComma = line.find(","); // Find the comma delimiter

            if (posComma == std::string::npos) {
                throw std::invalid_argument("Invalid format in database file.");
            }

            std::string date = line.substr(0, posComma); // Extract the date
            std::string valueStr = line.substr(posComma + 1); // Extract the value

            std::stringstream valueStream(valueStr); // Convert value to double using stringstream
            double value;
            valueStream >> value;

            if (valueStream.fail()) { // Check if conversion was successful
                throw std::invalid_argument("Invalid numeric value in database file.");
            }

            databaseMap.insert(std::make_pair(date, value)); // Insert into the map
        }
        index++;
    }
    return databaseMap; // Return the populated map
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
