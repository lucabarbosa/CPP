/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 09:30:46 by lbento            #+#    #+#             */
/*   Updated: 2026/05/14 15:31:09 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "Cat\033[0;33m default constructor called.\033[0m" << std::endl;
}

Cat::Cat(const Cat &other) : Animal("Cat")
{
	std::cout << "Cat\033[0;33m copy constructor called.\033[0m" << std::endl;
	*this = other;
}

Cat &Cat::operator=(const Cat &other)
{
	std::cout << "Cat\033[0;33m assignment operator called.\033[0m" << std::endl;
	if (this != &other)
		this->type = other.type;
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat\033[0;33m destructor called.\033[0m" << std::endl;
}
		
void  Cat::makeSound() const
{
	std::cout << "\033[0;34mRrr Meow-meow-meow!\033[0m" << std::endl;
}

void	Cat::setBrain(Brain &brain)
{
	this->brain = &brain;
}

const std::string *Cat::getBrain(void)
{
	return(brain->getIdeas());
}
