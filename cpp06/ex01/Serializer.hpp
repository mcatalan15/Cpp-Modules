#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
# include <cstddef>
#include "Data.hpp"

#ifndef UINTPTR_MAX
    typedef unsigned long uintptr_t; // or `unsigned int` depending on platform
#endif

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

