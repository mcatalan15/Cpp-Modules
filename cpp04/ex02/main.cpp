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

int	main()
{
	const AAnimal* i = new Cat();
	
	//Cases:
	//Creating a pointer works
	// const AAnimal *bear;
	// (void) bear;

	// Creating an AAnimal obect called pedro is not possible
	// const AAnimal pedro;
	// (void) pedro;

	delete i;
	
	Dog	Dog1;
	Dog	Dog2(Dog1);

	std::cout << std::endl;

	std::cout << "Dog1 address: " << &Dog1 << "\nDog2 address: " << &Dog2 << std::endl;
	std::cout << "Dog1 brain address: " << Dog1.getBrain() << "\nDog2 brain address: " << Dog2.getBrain() << std::endl;

	int	num = 6;
	AAnimal*	animals[num];

	for (int i = 0; i < num / 2; i++)
		animals[i] = new Dog();
	std::cout << std::endl;
	for (int i = num / 2; i < num; i++)
		animals[i] = new Cat();
	std::cout << std::endl;
	for (int i = 0; i < num; i++)
		delete animals[i];

	std::cout << std::endl;
	return 0;
}
