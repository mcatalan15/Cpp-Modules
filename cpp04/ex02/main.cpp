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
	// const AAnimal *bear;
	// (void) bear;
	// delete bear;
	// const AAnimal pedro;
	// (void) pedro;


	delete i;
	
	Dog	d1;
	Dog	d2(d1); //use also copy constructor

	std::cout << std::endl;

	std::cout << "d1 address: " << &d1 << "\nd2 address: " << &d2 << std::endl;
	std::cout << "d1 brain address: " << d1.getBrain() << "\nd2 brain address: " << d2.getBrain() << std::endl;

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
