/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 17:36:21 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/09/13 18:16:20 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

void basicTests()
{

	std::cout << std::endl
			  << "---- My own tests----" << std::endl;

	std::cout << std::endl
			  << "---- Constructors ----" << std::endl
			  << std::endl;

	Animal AnimalGen;
	Cat Garfield;
	Dog Oddie;

	std::cout << std::endl
			  << "---- Make sounds ----" << std::endl
			  << std::endl;

	std::cout << "Animal makes ";
	AnimalGen.makeSound();
	std::cout << "Cat makes ";
	Garfield.makeSound();
	std::cout << "Dog makes ";
	Oddie.makeSound();

	std::cout << std::endl
			  << "---- Destructors ----" << std::endl
			  << std::endl;
}

void mandatoryTest()
{

	std::cout << std::endl
			  << "---- Mandatory test----" << std::endl
			  << std::endl;
	const Animal *meta = new Animal();
	const Animal *j = new Dog();
	const Animal *i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();

	delete i;
	delete j;
	delete meta;
}

void failTests()
{
	std::cout << std::endl
			  << "---- Fail test----" << std::endl
			  << std::endl;
	const WrongAnimal *meta = new WrongAnimal();
	const WrongAnimal *i = new WrongCat();
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	meta->makeSound();

	delete i;
	delete meta;
}

int main()
{

	basicTests();
	mandatoryTest();
	failTests();

	return (0);
}