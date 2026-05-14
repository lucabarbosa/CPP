/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 09:31:41 by lbento            #+#    #+#             */
/*   Updated: 2026/05/14 16:27:30 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int   main(void)
{
	{
		std::cout << "\033[0;32m------------------" << std::endl;
		std::cout << "Testing with array and destructor" << std::endl;
		std::cout << "\033[0;32m------------------\033[0m" << std::endl;

		int	num = 6;
		Animal *animals[num];

		for (int i = 0; i < num/2; i++)
			animals[i] = new Cat();
		
		for (int i = 0; i < num/2; i++)
			animals[i] = new Dog();
		
		for (int i = 0; i < num; i++)
			animals[i]->makeSound();

		for (int i = 0; i < num; i++)
			delete animals[i];
	}
	{
		std::cout << "\033[0;32m------------------" << std::endl;
		std::cout << "Deep copy tests" << std::endl;
		std::cout << "\033[0;32m------------------\033[0m" << std::endl;

		Dog pluto;
		pluto.getBrain();
		Dog pluto2(pluto);

		std::cout << "d1 brain: " << &pluto.getBrain() << " | d2 brain: " << &d2.getBrain() << " (must differ)" << std::endl;

		d2.getBrain().setIdea(0, "I like cats");
		std::cout << "d1 idea[0]: " << d1.getBrain().getIdea(0)
		          << " <-- unchanged" << std::endl;
		std::cout << "d2 idea[0]: " << d2.getBrain().getIdea(0) << std::endl;

		Cat c1;
		c1.getBrain().setIdea(0, "I like fish");
		Cat c2 = c1;

		c2.getBrain().setIdea(0, "I like birds");
		std::cout << "c1 idea[0]: " << c1.getBrain().getIdea(0)
		          << " <-- unchanged" << std::endl;
		std::cout << "c2 idea[0]: " << c2.getBrain().getIdea(0) << std::endl;
	}
	return (0);
}
