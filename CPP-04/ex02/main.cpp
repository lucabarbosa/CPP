/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 09:31:41 by lbento            #+#    #+#             */
/*   Updated: 2026/05/14 17:26:08 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int   main(void)
{
	// Animal meta = new Animal();
	{
		std::cout << "\033[0;32m-------------------------------------------" << std::endl;
		std::cout << "testing polymorphism with an abstract class" << std::endl;
		std::cout << "-------------------------------------------\033[0m" << std::endl;

		const int	num = 4;
		Animal *animals[num];

		for (int i = 0; i < num / 2; i++)
			animals[i] = new Cat();

		for (int i = num / 2; i < num; i++)
			animals[i] = new Dog();
 
		for (int i = 0; i < num; i++)
			animals[i]->makeSound();
 
		for (int i = 0; i < num; i++)
			delete animals[i];
	}
	// {
	// 	std::cout << "\033[0;32m---------------" << std::endl;
	// 	std::cout << "Deep copy tests" << std::endl;
	// 	std::cout << "---------------\033[0m" << std::endl;
 
	// 	Brain smart;
	// 	smart.setIdea(0, "Catch the ball");
 
	// 	Dog pluto;
	// 	pluto.setBrain(smart);
	// 	Dog scooby(pluto);
 
	// 	std::cout << "\033[0;32mPluto brain addr: \033[0m" << &pluto.getBrain() << "\033[0;32m || Scooby brain: \033[0m"  << &scooby.getBrain() << std::endl;
	// 	std::cout << "\033[0;34mPluto idea[0]: \033[0m"  << pluto.getBrain().getIdea(0)  << std::endl;
	// 	std::cout << "\033[0;34mScooby idea[0]: \033[0m" << scooby.getBrain().getIdea(0) << std::endl;

	// 	Brain lazy;
	// 	lazy.setIdea(0, "I want catnip");

	// 	Cat tom;
	// 	tom.setBrain(lazy);
	// 	Cat felix(tom);

	// 	std::cout << "\033[0;32mTom brain addr: \033[0m" << &tom.getBrain() << "\033[0;32m || Felix brain: \033[0m"  << &felix.getBrain() << std::endl;
	// 	std::cout << "\033[0;34mTom idea[0]: \033[0m"   << tom.getBrain().getIdea(0)   << std::endl;
	// 	std::cout << "\033[0;34mFelix idea[0]: \033[0m" << felix.getBrain().getIdea(0) << std::endl;
	// }
	return (0);
}
