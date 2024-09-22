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
	std::cout << std::endl << "My test..." << std::endl;
	std::cout << "Creating animals..." << std::endl;
	const Animal *animal = new Animal();
	const Animal *dog = new Dog();
	const Animal *cat = new Cat();

	std::cout << std::endl << "Animal types:" << std::endl;
	std::cout << dog->getType() << " " << std::endl;
	std::cout << cat->getType() << " " << std::endl;

	std::cout << "\nCreating wrong animals..." << std::endl;

	const WrongAnimal *wrongAnimal = new WrongAnimal();
	const WrongAnimal *wrongCat = new WrongCat();

	std::cout << "\nSounds:" << std::endl;
	cat->makeSound();  // should output the cat sound
	dog->makeSound();  // should output the dog sound
	animal->makeSound(); // should output a generic animal sound
	std::cout << "\nWrongAnimal sounds:" << std::endl;
	wrongCat->makeSound();	// should output the wrong animal sound
	wrongAnimal->makeSound(); // should output a generic wrong animal sound

	std::cout << "\nCleaning up..." << std::endl;
	delete animal;
	delete dog;
	delete cat;
	delete wrongAnimal;
	delete wrongCat;
	return 0;
}