/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 12:20:09 by lbento            #+#    #+#             */
/*   Updated: 2026/05/14 15:32:42 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain\033[0;33m default constructor called.\033[0m" << std::endl;
	for (unsigned int i = 0; i < 100; i++)
		this->ideas[i] = "Aleatory idea";
}

Brain::Brain(std::string idea)
{
	std::cout << "Brain\033[0;33m default constructor for \033[0m" << idea << "\033[0;33m called.\033[0m" << std::endl;
	for (unsigned int i; i < 100; i++)
		this->ideas[i] = idea;
}

Brain::Brain(const Brain &other)
{
	std::cout << "Brain\033[0;33m copy constructor called.\033[0m" << std::endl;
	*this = other;
}

Brain &Brain::operator=(const Brain &other)
{
	std::cout << "Brain\033[0;33m assignment operator called.\033[0m" << std::endl;
	if (this != &other)
	{
		for (unsigned int i = 0; i < 100; i++)
			this->ideas[i] = other.ideas[i];
	}
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain\033[0;33m destructor called.\033[0m" << std::endl;
}

void	Brain::setIdeas(const std::string ideas[100])
{
	for (unsigned int i = 0; i < 100; i++)
		this->ideas[i] = ideas[i];
}

const std::string *Brain::getIdeas()
{
	return (this->ideas);
}

void	Brain::setIdea(int i, const std::string idea)
{
	if (i >= 100 || i < 0)
		return ;
	this->ideas[i] = idea;
}

const std::string	Brain::getIdea(int i)
{
	if (i >= 100 || i < 0)
		return ("-------empty------");
	return (this->ideas[i]);
}
