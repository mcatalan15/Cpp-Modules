#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
# include <cstddef>
#include "Data.hpp"

// Define uintptr_t if not already defined

#ifndef UINTPTR_MAX
    typedef unsigned long uintptr_t; // or `unsigned int` depending on platform
#endif

/*
	The Serializer class has two static methods:
		- serialize: that takes a Data pointer and returns a uintptr_t.
		- deserialize: that takes a uintptr_t and returns a Data pointer.
*/
class Serializer {

    public:
        static uintptr_t serialize(Data *ptr);
        static Data     *deserialize(uintptr_t raw);

    private:
        Serializer();
        Serializer(const Serializer &src);
        Serializer &operator=(const Serializer &src);
        ~Serializer();

};

#endif

