/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 17:36:21 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/09/17 16:39:42 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

void generalTest()
{

	std::cout << std::endl
			  << "------------------ My own tests-----------------" << std::endl;

	std::cout << std::endl
			  << "---- Constructors ----" << std::endl
			  << std::endl;

	Cat Garfield;
	Dog Oddie;

	std::cout << std::endl
			  << "---- Make sounds ----" << std::endl
			  << std::endl;

	std::cout << "Cat makes ";
	Garfield.makeSound();
	std::cout << "Dog makes ";
	Oddie.makeSound();

	std::cout << std::endl
			  << "---- Destructors ----" << std::endl
			  << std::endl;
}

void checkDeepCopy()
{

	std::cout << std::endl
			  << "------------- Check deep copies -------------" << std::endl
			  << std::endl;

	Dog originalDog;
	originalDog.getBrain()->setIdea("I am hungry");
	originalDog.getBrain()->setIdea("I am happy");
	originalDog.getBrain()->setIdea("I am sad");

	Dog copyDog = originalDog;

	std::cout << std::endl
			  << "-- Before modification --" << std::endl;
	std::cout << "-- Original dog --" << std::endl;
	originalDog.getBrain()->printIdeas();
	std::cout << "-- Copy dog --" << std::endl;
	copyDog.getBrain()->printIdeas();

	std::cout << std::endl
			  << "-- After modification --" << std::endl;
	copyDog.getBrain()->setIdea("I am rare");
	originalDog.getBrain()->setIdea("I am resting");
	std::cout << "-- Original dog --" << std::endl;
	originalDog.getBrain()->printIdeas();
	std::cout << "-- Copy dog --" << std::endl;
	copyDog.getBrain()->printIdeas();
}

void checkAbsClass()
{

	std::cout << std::endl
			  << "----------------- Checking abstract class -----------------" << std::endl
			  << std::endl;

	// AAnimal tiger;

	// AAnimal* zebra = new AAnimal;
	// delete zebra;

	Cat *lion = new Cat();
	lion->makeSound();

	delete lion;
}

int main()
{

	generalTest();
	checkDeepCopy();
	checkAbsClass();
	return (0);
}

// int	main()
// {
// 	/*const Animal* i = new Cat();
// 	//const Cat *i = new Cat();
	
// 	delete i;*/
	
// 	/*Dog	d1;
// 	Dog	d2(d1); //use also copy constructor

// 	std::cout << std::endl;
// 	//d2 = d1;

// 	std::cout << "d1 address: " << &d1 << "\nd2 address: " << &d2 << std::endl;
// 	std::cout << "d1 brain address: " << d1.getBrain() << "\nd2 brain address: " << d2.getBrain() << std::endl;*/

// 	int	num = 6;
// 	AAnimal*	animals[num];

// 	for (int i = 0; i < num / 2; i++)
// 		animals[i] = new Dog();
// 	std::cout << std::endl;
// 	for (int i = num / 2; i < num; i++)
// 		animals[i] = new Cat();
// 	std::cout << std::endl;
// 	for (int i = 0; i < num; i++)
// 		delete animals[i];

// 	std::cout << std::endl;
// 	return 0;
// }
