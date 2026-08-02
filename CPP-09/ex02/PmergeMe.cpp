/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 00:54:07 by lbento            #+#    #+#             */
/*   Updated: 2026/07/26 00:48:31 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void)
{

}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	*this = other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		_vecResult = other._vecResult;
		_deqResult = other._deqResult;
	}
	return (*this);
}

PmergeMe::~PmergeMe(void)
{

}

void	PmergeMe::checkNumbers(int argc, char **argv)
{
	for (int i = 1; i < argc; i++)
	{
		std::string	arg(argv[i]);
		if (arg.empty())
			throw std::invalid_argument("\033[0;31m Empty input.\033[0m");
		if (std::isspace(static_cast<unsigned char>(arg[0])))
			throw std::invalid_argument("\033[0;31m Invalid argument:\033[0m " + arg);
		errno = 0;
		char	*end;
		long	value = std::strtol(arg.c_str(), &end, 10);
		if (*end != '\0')
			throw std::invalid_argument("\033[0;31m Invalid argument:\033[0m " + arg);
		if (value <= 0)
			throw std::invalid_argument("\033[0;31m Negative argument:\033[0m " + arg);
		if (value >= static_cast<long>(INT_MAX))
			throw std::invalid_argument("\033[0;31m Out of range of integers:\033[0m " + arg);
		if (errno == ERANGE)
			throw std::invalid_argument("\033[0;31m Out of range of integers:\033[0m " + arg);
		for (std::vector<int>::iterator j = _vecResult.begin(); j != _vecResult.end(); ++j)
			if (*j == static_cast<int>(value))
				throw std::invalid_argument("\033[0;31m Duplicated argument:\033[0m " + arg);
		_vecResult.push_back(static_cast<int>(value));
		_deqResult.push_back(static_cast<int>(value));
	}
}

int	PmergeMe::sortVec(void)
{
	return (0);
}

int	PmergeMe::sortDeq(void)
{
	return (0);
}

void	PmergeMe::printNum(void)
{
	std::vector<int>::iterator num;
	std::cout << "\033[1;37m";
	for (num = _vecResult.begin(); num != _vecResult.end(); ++num)
	{
		std::cout << *num;
		if (num + 1 != _vecResult.end())
			std::cout << " ";
	}
	std::cout << "\033[0m" << std::endl;
}

void	PmergeMe::printTime(void)
{
	std::cout << "\033[0;33mTime to process a range of \033[0;37m" << _vecResult.size() << "\033[0;33m elements with std::vector : \033[0m";
	std::cout << _timeVec << std::endl;
	std::cout << "\033[0;33mTime to process a range of \033[0;37m" << _vecResult.size() << "\033[0;33m elements with std::deque  : \033[0m";
	std::cout << _timeDeq << std::endl;
}
