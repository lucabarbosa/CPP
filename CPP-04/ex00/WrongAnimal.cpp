/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 09:33:26 by lbento            #+#    #+#             */
/*   Updated: 2026/05/14 11:25:48 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("Any WrongAnimal")
{
	std::cout << "Wrong Animal\033[0;31m default constructor called.\033[0m" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : type(type)
{
	std::cout << "Wrong Animal\033[0;31m default constructor for \033[0m" << type << "\033[0;31m called.\033[0m" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
	std::cout << "Wrong Animal\033[0;31m copy constructor called.\033[0m" << std::endl;
	*this = other;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
	std::cout << "Wrong Animal\033[0;31m assignment operator called.\033[0m" << std::endl;
	if (this != &other)
		this->type = other.type;
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Wrong Animal\033[0;31m destructor called.\033[0m" << std::endl;
}

std::string	WrongAnimal::getType() const
{
	return (type);
}

void	WrongAnimal::setType(const std::string &type)
{
	this->type = type;
}

void	WrongAnimal::makeSound() const
{
	std::cout << "\033[0;34mEXOTIC AND STRANGE SOUND!\033[0m" << std::endl;
}
