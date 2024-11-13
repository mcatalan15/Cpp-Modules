#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#define CYAN "\033[36m"
#define RESET "\033[0m"
#define RED "\033[31m"

template <class T>
class Array {
    private:
        T*              _arr;
        unsigned int    _n;

    public:
        Array();
        Array(unsigned int n);
        Array(const Array &src);
        Array &operator=(const Array &src);
        ~Array();
        
        T &operator[](unsigned int n);
        unsigned int    size() const;
};

#endif
