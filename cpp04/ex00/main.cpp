/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 17:36:21 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/09/20 17:12:37 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int	main (void) {
	{
	std::cout << std::endl << "----- ANIMALS -----" << std::endl;
	const	Animal	*animal = new Animal();
	const	Animal	*dog = new Dog();
	const	Animal	*cat = new Cat();

	std::cout << std::endl;
	std::cout << dog->getType() << ": ";
	dog->makeSound();
	std::cout << cat->getType() << ": ";
	cat->makeSound(); //will output the cat sound!

	animal->makeSound();
	delete animal;
	delete dog;
	delete cat;
	}
	{
	std::cout << std::endl << "----- WRONGANIMALS -----" << std::endl;
	const	WrongAnimal	*wronganimal = new WrongAnimal();
	const	WrongAnimal	*wrongcat = new WrongCat("WrongCat");

	std::cout << "WrongAimal: " << wronganimal->getType() << ": ";
	wronganimal->makeSound();
	std::cout << "WrongCat: " << wrongcat->getType() << ": ";
	wrongcat->makeSound();

	delete wronganimal;
	delete wrongcat;
	}
	std::cout << "----- END -----" << std::endl;
	return 0;
}