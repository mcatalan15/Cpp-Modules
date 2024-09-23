/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 17:36:21 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/09/13 19:12:09 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int	main()
{
	{
	std::cout << "------- Ideas mem addr -------" << std::endl;
	Dog	Dog1;
	Dog	Dog2(Dog1);

	std::cout << std::endl;
	// Dog2 = Dog1;

	std::cout << "Dog1 address: " << &Dog1 << "\nDog2 address: " << &Dog2 << std::endl;
	std::cout << "Dog1 brain address: " << Dog1.getBrain() << "\nDog2 brain address: " << Dog2.getBrain() << std::endl;
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
