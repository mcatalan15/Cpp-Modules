#ifndef MUTANTSTACK_HPP
#define MUTANSTACK_HPP

 include <iostream>
#include <stack>

#define RESET "\033[0m"
#define RED "\033[31m"

template<typename T>
class MutanStack : public std::stack<T> {
    public:
        MutantStack();
        MutantStack(const MutantStack &src);
        ~MutantStack();

        MutantStack &operator=(const MutantStack &src);
    
        typedef typename std::stack<T>::container_type::iterator iterator;
        iterator    begin();
        iterator    end();
};

#endif
