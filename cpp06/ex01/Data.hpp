#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>

using std::string;

/*
	This structure is used to store the data that will be serialized.
	In this specific case, the structure has two members:
		- i: an integer that will be serialized.
		- info: a string that will be serialized.
*/
typedef struct s_data {
    int     i;
    string  info;
} Data;

#endif
