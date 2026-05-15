/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 09:31:41 by lbento            #+#    #+#             */
/*   Updated: 2026/05/15 17:44:20 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int   main(void)
{
	{
		std::cout << "\033[0;32m------------------" << std::endl;
		std::cout << "TESTS FROM SUBJECT" << std::endl;
		std::cout << "\033[0;32m------------------\033[0m" << std::endl;
		const Animal* meta = new Animal();
      const Animal* j = new Dog();
      const Animal* i = new Cat();
      std::cout << j->getType() << " ";
      i->makeSound();
      std::cout << i->getType() << " ";
      j->makeSound();
		std::cout << meta->getType() << " ";
      meta->makeSound();
      delete meta;
      delete i;
      delete j;
	}
	{
		std::cout << "\033[0;32m------------------------" << std::endl;
		std::cout << "TESTS WITHOUT ALLOCATION" << std::endl;
		std::cout << "\033[0;32m------------------------\033[0m" << std::endl;
		Animal Any;
		Any.makeSound();
		Dog Pluto;
		Pluto.makeSound();
		Cat Tom;
		Tom.makeSound();
	}
	{
		std::cout << "\033[0;32m--------------------------------" << std::endl;
		std::cout << "TESTS ALOCATED WITH WRONG ANIMAL" << std::endl;
		std::cout << "\033[0;32m--------------------------------\033[0m" << std::endl;
      const WrongAnimal* meta = new WrongAnimal();
      const WrongAnimal* i = new WrongCat();
      std::cout << i->getType() << " " << std::endl;
      i->makeSound();
      meta->makeSound();
      delete meta;
      delete i;
	}
	{
		std::cout << "\033[0;32m-----------------------------------------" << std::endl;
		std::cout << "TESTS WITHOUT ALLOCATION AND WRONG ANIMAL" << std::endl;
		std::cout << "\033[0;32m-----------------------------------------\033[0m" << std::endl;
		WrongAnimal Any;
		Any.makeSound();
		WrongCat Tom;
		Tom.makeSound();
	}
	return (0);
}
