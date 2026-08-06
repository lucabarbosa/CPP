/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 00:54:07 by lbento            #+#    #+#             */
/*   Updated: 2026/08/02 07:36:20 by lbento           ###   ########.fr       */
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

static double getTime(void);

void	PmergeMe::sortVec(void)
{
	double start;
	double end;
	start = getTime();
	_vecResult = fordJohnsonVec(_vecResult);
	end = getTime();
	_timeVec = end - start;
}

std::vector<int> fordJohnsonVec(std::vector<int> input)
{
	bool	isUnpaired;
	int	unpaired = 0;
	isUnpaired = (input.size() % 2 != 0);
	if (isUnpaired)
	{
		unpaired = input.back();
		input.pop_back();
	}
	std::vector<int> smalls;
	std::vector<int> bigs;
	for (size_t i = 0;i < input.size(); i++)
	{
		if (input[i] < input[i + 1])
		{
			smalls.push_back(input[i]);
			bigs.push_back(input[i + 1]);
		}
		else
		{
			smalls.push_back(input[i + 1]);
			bigs.push_back(input[i]);
		}
	}
}

void	PmergeMe::sortDeq(void)
{
	double start;
	double end;
	start = getTime();
	_deqResult = fordJohnsonDeq(_deqResult);
	end = getTime();
	_timeDeq = end - start;
}

void	PmergeMe::printVec(void)
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

void	PmergeMe::printDeq(void)
{
	std::deque<int>::iterator num;
	std::cout << "\033[1;37m";
	for (num = _deqResult.begin(); num != _deqResult.end(); ++num)
	{
		std::cout << *num;
		if (num + 1 != _deqResult.end())
			std::cout << " ";
	}
	std::cout << "\033[0m" << std::endl;
}

static double getTime(void)
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000000.0 + tv.tv_usec);
}

void	PmergeMe::printTime(void)
{
	std::cout << std::fixed << std::setprecision(5);
	std::cout << "\033[0;33mTime to process a range of \033[0;37m" << _vecResult.size() << "\033[0;33m elements with std::vector : \033[0m";
	std::cout << _timeVec << " us" << std::endl;
	std::cout << "\033[0;33mTime to process a range of \033[0;37m" << _vecResult.size() << "\033[0;33m elements with std::deque  : \033[0m";
	std::cout << _timeDeq << " us" << std::endl;
}
