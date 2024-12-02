#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>

# define RESET "\033[0m"
# define RED "\033[31m"

template <typename T>

typename T::const_iterator  easyfind(const T& cont, int nb) {
    typename T::const_iterator it = std::find(cont.begin(), cont.end(), nb);
    if (it != cont.end())
        return it;
    else
        throw std::exception();
}

#endif
