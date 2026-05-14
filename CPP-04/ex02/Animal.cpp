/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 09:30:10 by lbento            #+#    #+#             */
/*   Updated: 2026/05/14 17:21:42 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Any Animal")
{
	std::cout << "Animal\033[0;33m default constructor called.\033[0m" << std::endl;
}

Animal::Animal(std::string type) : type(type)
{
	std::cout << "Animal\033[0;33m default constructor for \033[0m" << type << "\033[0;33m called.\033[0m" << std::endl;
}

Animal::Animal(const Animal &other)
{
	std::cout << "Animal\033[0;33m copy constructor called.\033[0m" << std::endl;
	*this = other;
}

Animal &Animal::operator=(const Animal &other)
{
	std::cout << "Animal\033[0;33m assignment operator called.\033[0m" << std::endl;
	if (this != &other)
		this->type = other.type;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal\033[0;33m destructor called.\033[0m" << std::endl;
}

std::string	Animal::getType() const
{
	return (type);
}

void	Animal::setType(const std::string &type)
{
	this->type = type;
}
