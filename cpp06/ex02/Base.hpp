#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>

/*
	Class A, B and C inherit from Base.
	Base is a pure virtual class for the purpose of this exercise.
*/
class Base {
    public:
        virtual ~Base(){};
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

#endif
