/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 08:03:57 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/09/04 19:59:41 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

/*
	This function will replace the string str2 with str3
	
	Given a string str, it will look for the string str2
	When it finds it, it will replace it with str3
	Then it will return the new string
*/

std::string newStr(std::string str, char *argv2, char *argv3) {

	int	pos = 0;
	std::string	newStr;
	std::string	original;
	std::string	str2 = argv2;
	std::string	str3 = argv3;

	pos = (str.find(str2));
	if (pos >= 0) {
		while (pos >= 0) {
			std::string original = str.substr(0, pos);
			newStr += original + str3;
			str = str.substr(pos + str2.length());
			pos = str.find(str2);
		}
	}
	newStr = newStr + str;
	return (newStr);
}

/*
	Main function
		- Check if the number of arguments is correct
		- Check if the file given is valid with ifstream (infile.is_open())
		- Create the new file with ofstream (newFile.is_open())
		- Replace the string with the newStr function
		- Write the new string to the new file
*/

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

