/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 08:03:57 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/09/04 12:42:33 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

std::string newStr(std::string line, char *argv2, char *argv3) {}

int	main(int argc, char **argv)	{

	if (argc == 4) {
		//Create the replacement file
		std::ifstream infile(argv[1]);
		if (!infile.is_open())	{
			std::cout << "Invalid file" << std::endl;
			return (1);
		}
		std::string newFileName = std::string(argv[1]) + ".replace";
		//Check if there is any error
		std::ofstream newFile(newFileName.c_str());
		if (!newFile.is_open())	{
			std::cout << "New file has an error" << std::endl;
			return (1);
		}
		//add to replacemente the replacement str
		std::string str;
		while (std::getline(infile, str))	{
			std::string pStr = newStr(str, argv[2], argv[3]);
			newFile << pStr << std::endl;
		}
	}
	else	{
		std::cout << "Invalid parameters\n";
		std::cout << "\t3 arguements: File, str1, str2" << std::endl;
		return (1);
	}
	return (0);
}

