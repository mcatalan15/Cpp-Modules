/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 17:36:21 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/09/24 21:26:11 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

/*
	With this main we can see how the Dog and Cat classes work.
	We can check that each has a brain and that the brain(idea addres) is different
	for each object.
*/

int	main()
{
	{
	std::cout << "------- Ideas mem addr -------" << std::endl;
	std::cout << "--- DOG ---" << std::endl;
	Dog	Dog1;
	Dog	Dog2(Dog1);

	std::cout << std::endl;

	std::cout << "Dog1 address: " << &Dog1 << "\nDog2 address: " << &Dog2 << std::endl;
	std::cout << "Dog1 brain address: " << Dog1.getBrain() << "\nDog2 brain address: " << Dog2.getBrain() << std::endl;
	}
	{
	std::cout << std::endl << "--- CAT ---" << std::endl;
	Cat Cat1;
	Cat Cat2(Cat1);

	std::cout << std::endl;

	std::cout << "Cat1 address: " << &Cat1 << "\nCat2 address: " << &Cat2 << std::endl;
	std::cout << "Cat1 brain address: " << Cat1.getBrain() << "\nCat2 brain address: " << Cat2.getBrain() << std::endl;
	}
	{
	std::cout << std::endl << "------- For test -------" << std::endl;
	int	num = 6;
	Animal*	animals[num];

	for (int i = 0; i < num / 2; i++)
		animals[i] = new Dog();
	std::cout << std::endl;
	for (int i = num / 2; i < num; i++)
		animals[i] = new Cat();
	std::cout << std::endl;
	for (int i = 0; i < num; i++)
		delete animals[i];

	std::cout << "------- End -------" << std::endl;
	}
	return 0;
}
