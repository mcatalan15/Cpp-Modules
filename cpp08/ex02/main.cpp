#include "MutanStack.hpp"
#include <list>

void    mandatoryTest() {
    std::cout << std::endl << "----- mutant stack class -----" << MutanStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    MutanStack<int>::iterator it = mstack.begin();
    MutanStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite) {
        std::cout << *it << std::endl;
        +it;
    }
    std::stack<int> s(mstack);
}

void    listTest() {
    std::cout << std::endl << "-------list------" << std::endl;
    std::list<int> list;
    list.push_back(5);
}

int int main () {
    return 0;
}

