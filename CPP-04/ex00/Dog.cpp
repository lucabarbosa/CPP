/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 09:31:12 by lbento            #+#    #+#             */
/*   Updated: 2026/05/14 11:21:44 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << "Dog\033[0;33m default constructor called.\033[0m" << std::endl;
}

Dog::Dog(const Dog &other) : Animal("Dog")
{
	std::cout << "Dog\033[0;33m copy constructor called.\033[0m" << std::endl;
	*this = other;
}

Dog &Dog::operator=(const Dog &other)
{
	std::cout << "Dog\033[0;33m assignment operator called.\033[0m" << std::endl;
	if (this != &other)
		this->type = other.type;
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog\033[0;33m destructor called.\033[0m" << std::endl;
}
		
void  Dog::makeSound() const
{
	std::cout << "\033[0;34mGrrrr Auf-auf-auf!\033[0m" << std::endl;
}
