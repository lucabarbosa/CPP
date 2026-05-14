/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 09:33:59 by lbento            #+#    #+#             */
/*   Updated: 2026/05/14 11:26:40 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << "Wrong Cat\033[0;31m default constructor called.\033[0m" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal("WrongCat")
{
	std::cout << "Wrong Cat\033[0;31m copy constructor called.\033[0m" << std::endl;
	*this = other;
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
	std::cout << "Wrong Cat\033[0;31m assignment operator called.\033[0m" << std::endl;
	if (this != &other)
		this->type = other.type;
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "Wrong Cat\033[0;31m destructor called.\033[0m" << std::endl;
}
		
void  WrongCat::makeSound() const
{
	std::cout << "\033[0;34mRrr Meow-meow-meow!\033[0m" << std::endl;
}