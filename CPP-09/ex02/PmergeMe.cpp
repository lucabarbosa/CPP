/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 00:54:07 by lbento            #+#    #+#             */
/*   Updated: 2026/08/13 18:16:55 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) : _timeVec(0), _timeDeq(0)
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
		_timeVec = other._timeVec;
		_timeDeq = other._timeDeq;
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

static std::vector<size_t>	getJacobsthalOrder(size_t pendSize)
{
	std::vector<size_t>	order;

	if (pendSize == 0)
		return (order);
	order.push_back(2);
	if (pendSize == 1)
		return (order);

	std::vector<size_t>	jac;
	jac.push_back(0);
	jac.push_back(1);
	while (jac.back() <= pendSize + 1)
		jac.push_back(jac[jac.size() - 1] + 2 * jac[jac.size() - 2]);

	size_t	prev = 2;
	for (size_t idx = 3; idx < jac.size(); idx++)
	{
		size_t	curr = jac[idx];
		if (curr > pendSize + 1)
			curr = pendSize + 1;
		for (size_t k = curr; k > prev; k--)
			order.push_back(k);
		prev = curr;
		if (prev >= pendSize + 1)
			break;
	}
	return (order);
}

std::vector<int>	fordJohnsonVec(std::vector<int> input)
{
	if (input.size() <= 1)
		return (input);

	bool	hasStray = (input.size() % 2 != 0);
	int		stray = 0;
	if (hasStray)
	{
		stray = input.back();
		input.pop_back();
	}

	std::vector<std::pair<int, int> >	pairs;
	for (size_t i = 0; i < input.size(); i += 2)
	{
		if (input[i] > input[i + 1])
			pairs.push_back(std::make_pair(input[i], input[i + 1]));
		else
			pairs.push_back(std::make_pair(input[i + 1], input[i]));
	}

	std::vector<int>	largers;
	for (size_t i = 0; i < pairs.size(); i++)
		largers.push_back(pairs[i].first);

	std::vector<int>	sortedLargers = fordJohnsonVec(largers);
	std::vector<int>	mainChain(sortedLargers);

	for (size_t i = 0; i < pairs.size(); i++)
	{
		if (pairs[i].first == sortedLargers[0])
		{
			mainChain.insert(mainChain.begin(), pairs[i].second);
			break;
		}
	}

	std::vector<int>	pend;
	for (size_t i = 1; i < sortedLargers.size(); i++)
	{
		for (size_t j = 0; j < pairs.size(); j++)
		{
			if (pairs[j].first == sortedLargers[i])
			{
				pend.push_back(pairs[j].second);
				break;
			}
		}
	}

	std::vector<size_t>	order = getJacobsthalOrder(pend.size());
	for (size_t i = 0; i < order.size(); i++)
	{
		size_t	pendIdx = order[i] - 2;
		if (pendIdx >= pend.size())
			continue;
		int		value = pend[pendIdx];
		std::vector<int>::iterator	limit;
		limit = std::find(mainChain.begin(), mainChain.end(), sortedLargers[pendIdx + 1]);
		std::vector<int>::iterator	pos = std::lower_bound(mainChain.begin(), limit, value);
		mainChain.insert(pos, value);
	}

	if (hasStray)
	{
		std::vector<int>::iterator	pos;
		pos = std::lower_bound(mainChain.begin(), mainChain.end(), stray);
		mainChain.insert(pos, stray);
	}
	return (mainChain);
}

std::deque<int>	fordJohnsonDeq(std::deque<int> input)
{
	if (input.size() <= 1)
		return (input);

	bool	hasStray = (input.size() % 2 != 0);
	int		stray = 0;
	if (hasStray)
	{
		stray = input.back();
		input.pop_back();
	}

	std::deque<std::pair<int, int> >	pairs;
	for (size_t i = 0; i < input.size(); i += 2)
	{
		if (input[i] > input[i + 1])
			pairs.push_back(std::make_pair(input[i], input[i + 1]));
		else
			pairs.push_back(std::make_pair(input[i + 1], input[i]));
	}

	std::deque<int>	largers;
	for (size_t i = 0; i < pairs.size(); i++)
		largers.push_back(pairs[i].first);

	std::deque<int>	sortedLargers = fordJohnsonDeq(largers);
	std::deque<int>	mainChain(sortedLargers);

	for (size_t i = 0; i < pairs.size(); i++)
	{
		if (pairs[i].first == sortedLargers[0])
		{
			mainChain.insert(mainChain.begin(), pairs[i].second);
			break;
		}
	}

	std::deque<int>	pend;
	for (size_t i = 1; i < sortedLargers.size(); i++)
	{
		for (size_t j = 0; j < pairs.size(); j++)
		{
			if (pairs[j].first == sortedLargers[i])
			{
				pend.push_back(pairs[j].second);
				break;
			}
		}
	}

	std::vector<size_t>	order = getJacobsthalOrder(pend.size());
	for (size_t i = 0; i < order.size(); i++)
	{
		size_t	pendIdx = order[i] - 2;
		if (pendIdx >= pend.size())
			continue;
		int		value = pend[pendIdx];
		std::deque<int>::iterator	limit;
		limit = std::find(mainChain.begin(), mainChain.end(), sortedLargers[pendIdx + 1]);
		std::deque<int>::iterator	pos = std::lower_bound(mainChain.begin(), limit, value);
		mainChain.insert(pos, value);
	}

	if (hasStray)
	{
		std::deque<int>::iterator	pos;
		pos = std::lower_bound(mainChain.begin(), mainChain.end(), stray);
		mainChain.insert(pos, stray);
	}
	return (mainChain);
}

void	PmergeMe::sortVec(void)
{
	clock_t	start;
	clock_t	end;

	start = clock();
	_vecResult = fordJohnsonVec(_vecResult);
	end = clock();
	_timeVec = static_cast<double>(end - start) * 1000000.0 / CLOCKS_PER_SEC;
}

void	PmergeMe::sortDeq(void)
{
	clock_t	start;
	clock_t	end;

	start = clock();
	_deqResult = fordJohnsonDeq(_deqResult);
	end = clock();
	_timeDeq = static_cast<double>(end - start) * 1000000.0 / CLOCKS_PER_SEC;
}

void	PmergeMe::printVec(void)
{
	std::cout << "\033[1;37m";
	for (std::vector<int>::iterator num = _vecResult.begin(); num != _vecResult.end(); ++num)
	{
		std::cout << *num;
		if (num + 1 != _vecResult.end())
			std::cout << " ";
	}
	std::cout << "\033[0m" << std::endl;
}

void	PmergeMe::printDeq(void)
{
	std::cout << "\033[1;37m";
	for (std::deque<int>::iterator num = _deqResult.begin(); num != _deqResult.end(); ++num)
	{
		std::cout << *num;
		if (num + 1 != _deqResult.end())
			std::cout << " ";
	}
	std::cout << "\033[0m" << std::endl;
}

void	PmergeMe::printTime(void)
{
	std::cout << std::fixed << std::setprecision(0);
	std::cout << "\033[0;33mTime to process a range of \033[0;37m" << _vecResult.size()
		<< "\033[0;33m elements with std::vector : \033[0m" << _timeVec << " µs" << std::endl;
	std::cout << "\033[0;33mTime to process a range of \033[0;37m" << _deqResult.size()
		<< "\033[0;33m elements with std::deque  : \033[0m" << _timeDeq << " µs" << std::endl;
}