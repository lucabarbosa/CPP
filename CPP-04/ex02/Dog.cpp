/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 09:31:12 by lbento            #+#    #+#             */
/*   Updated: 2026/05/14 16:58:34 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog"), brain(new Brain())
{
	std::cout << "Dog\033[0;33m default constructor called.\033[0m" << std::endl;
}

Dog::Dog(const Dog &other) : Animal("Dog"), brain(new Brain(*other.brain))
{
	std::cout << "Dog\033[0;33m copy constructor called.\033[0m" << std::endl;
	this->type = other.type;
}

Dog &Dog::operator=(const Dog &other)
{
	std::cout << "Dog\033[0;33m assignment operator called.\033[0m" << std::endl;
	if (this != &other)
	{
		this->type = other.type;
		delete this->brain;
		this->brain = new Brain(*other.brain);
	}
	return (*this);
}

Dog::~Dog()
{
	delete brain;
	std::cout << "Dog\033[0;33m destructor called.\033[0m" << std::endl;
}
		
void  Dog::makeSound() const
{
	std::cout << "\033[0;34mGrrrr Auf-auf-auf!\033[0m" << std::endl;
}

void	Dog::setBrain(const Brain &brain)
{
	*this->brain = brain;
}

Brain &Dog::getBrain(void)
{
	return(*brain);
}
