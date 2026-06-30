/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 09:37:37 by lbento            #+#    #+#             */
/*   Updated: 2026/06/30 00:42:57 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void)
{

}

Span::Span(unsigned int N) : _maxSize(N)
{

}

Span::Span(const Span &other) : _maxSize(other._maxSize), _numbers(other._numbers)
{

}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		_maxSize = other._maxSize;
		_numbers = other._numbers;
	}
	return (*this);
}

Span::~Span(void)
{
	
}

void	Span::addNumber(int number)
{
	if (_maxSize <= 0)
		throw	std::length_error("\033[0;31mCannot insert number(s). Vector doesn't comport any number.\033[0m");
	if (_numbers.size() >= _maxSize)
		throw	std::length_error("\033[0;31mCannot insert number(s). Vector is full of numbers.\033[0m");
	_numbers.push_back(number);
}

int	Span::shortestSpan(void)
{
	if (_numbers.size() <= 1)
		throw	std::length_error("\033[0;31mNeed more numbers to calculate shortest span.\033[0m");
	std::sort(_numbers.begin(), _numbers.end());
	int	shortest = _numbers.at(1) - _numbers.at(0);
	int	temp = 0;
	for (size_t i = 1; i < _numbers.size() - 1; i++)
	{
		temp = _numbers.at(i + 1) - _numbers.at(i);
		if (temp < shortest)
			shortest = temp;
	}
	return (shortest);
}
int	Span::longestSpan(void)
{
	if (_numbers.size() <= 1)
		throw	std::length_error("\033[0;31mNeed more numbers to calculate longest span.\033[0m");
	std::sort(_numbers.begin(), _numbers.end());
	return (_numbers.back() - _numbers.front());
}

void	Span::addArray(unsigned int size)
{
	if (_maxSize <= 0)
		throw	std::length_error("\033[0;31mCannot insert number(s). Vector doesn't comport any number.\033[0m");
	for (unsigned int i = 0; i < size; i++)
	{
		if (i >= _maxSize)
			throw	std::length_error("\033[0;31mCannot insert number(s). Vector is full of numbers.\033[0m");
		_numbers.push_back(i + 1);
	}
}
