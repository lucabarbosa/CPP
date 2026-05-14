/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 09:30:46 by lbento            #+#    #+#             */
/*   Updated: 2026/05/14 17:01:45 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat"), brain(new Brain())
{
	std::cout << "Cat\033[0;33m default constructor called.\033[0m" << std::endl;
}

Cat::Cat(const Cat &other) : Animal("Cat"), brain(new Brain(*other.brain))
{
	std::cout << "Cat\033[0;33m copy constructor called.\033[0m" << std::endl;
	this->type = other.type;
}

Cat &Cat::operator=(const Cat &other)
{
	std::cout << "Cat\033[0;33m assignment operator called.\033[0m" << std::endl;
	if (this != &other)
	{
		this->type = other.type;
		delete this->brain;
		this->brain = new Brain(*other.brain);
	}
	return (*this);
}

Cat::~Cat()
{
	delete brain;
	std::cout << "Cat\033[0;33m destructor called.\033[0m" << std::endl;
}
		
void  Cat::makeSound() const
{
	std::cout << "\033[0;34mRrr Meow-meow-meow!\033[0m" << std::endl;
}

void	Cat::setBrain(const Brain &brain)
{
	*this->brain = brain;
}

Brain &Cat::getBrain(void)
{
	return(*brain);
}
