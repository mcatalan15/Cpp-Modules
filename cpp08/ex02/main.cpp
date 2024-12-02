#include "MutantStack.hpp"
#include <list>
#include "MutantStack.tpp"

void    mandatoryTest() {
    std::cout << std::endl << "----- mutant stack class -----" << std::endl;
    MutantStack<int> mstack;
	mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
}

void    listTest() {
    std::cout << std::endl << "-------list------" << std::endl;
    std::list<int> list;
    list.push_back(5);
    list.push_back(17);
    std::cout << list.back() << std::endl;
    list.pop_back();
    std::cout << list.size() << std::endl;
    list.push_back(3);
    list.push_back(5);
    list.push_back(737);
    std::list<int>::iterator it = list.begin();
    std::list<int>::iterator ite = list.end();
    ++it;
    --it;
    while(it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }
    std::list<int> s(list);
}

void    myOwnTest() {
    std::cout << std::endl << "--------- my own test --------" << std::endl;
    MutantStack<int> st;
    st.push(-2);
    st.push(5);
    st.push(4);
    st.push(3);

    st.pop();

    std::cout << "first element: " << *st.begin() << std::endl;
    std::cout << "last element: " << *--(st.end()) << std::endl;

    std::cout << std::endl << "------ = operator -----" << std::endl;
    MutantStack<int> stCopy = st;
    std::cout << "first element copy: " << *stCopy.begin() << std::endl;
    std::cout << "last element copy: " << *--(stCopy.end()) << std::endl;
}

int main () {
    mandatoryTest();
    listTest();
    myOwnTest();
    return 0;
}

