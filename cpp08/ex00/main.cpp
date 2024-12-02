#include "easyfind.hpp"
#include <vector>
#include <deque>

void    vectorTests() {
    std::vector<int> vect;
    vect.push_back(1);
    vect.push_back(4);
    vect.push_back(6);
    vect.push_back(64);
    vect.push_back(-123);

    std::cout <<std::endl << "---- existing number -----" << std::endl;
    try {
        std::vector<int>::const_iterator it = easyfind(vect, 4);
        std::cout << "Number " << *it << std::endl;
    }
    catch (std::exception e) {
        std::cout << RED << "Not found" << RESET << std::endl;
    }
    std::cout <<std::endl << "---- not existing number -----" << std::endl;
    try {
        std::vector<int>::const_iterator it = easyfind(vect, 17);
        std::cout << "Number " << *it << std::endl;
    }
    catch (std::exception e) {
        std::cout << RED << "Not found" << RESET << std::endl;
    }
    std::cout <<std::endl << "---- not existing number -----" << std::endl;
    try {
        std::vector<int>::const_iterator it = easyfind(vect, -211);
        std::cout << "Number " << *it << std::endl;
    }
    catch (std::exception e) {
        std::cout << RED << "Not found" << RESET << std::endl;
    }
}

void    queueTests() {
    std::deque<int> vect;
    vect.push_back(100);
    vect.push_back(-123);
    vect.push_back(321);
    vect.push_back(1);
    vect.push_back(3);

    std::cout <<std::endl << "---- existing number -----" << std::endl;
    try {
        std::deque<int>::const_iterator it = easyfind(vect, 4);
        std::cout << "Number " << *it << std::endl;
    }
    catch (std::exception e) {
        std::cout << RED << "Not found" << RESET << std::endl;
    }
    std::cout <<std::endl << "---- not existing number -----" << std::endl;
    try {
        std::deque<int>::const_iterator it = easyfind(vect, 17);
        std::cout << "Number " << *it << std::endl;
    }
    catch (std::exception e) {
        std::cout << RED << "Not found" << RESET << std::endl;
    }
    std::cout <<std::endl << "---- not existing number -----" << std::endl;
    try {
        std::deque<int>::const_iterator it = easyfind(vect, -211);
        std::cout << "Number " << *it << std::endl;
    }
    catch (std::exception e) {
        std::cout << RED << "Not found" << RESET << std::endl;
    }
}

int main () {
    vectorTests();
    queueTests();

    return 0;
}
