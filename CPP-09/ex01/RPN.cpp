/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 00:51:45 by lbento            #+#    #+#             */
/*   Updated: 2026/07/22 00:43:53 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(void)
{

}

RPN::RPN(const RPN &other)
{
	*this = other;
}

RPN& RPN::operator=(const RPN &other)
{
	(void)other;
	return (*this);
}

RPN::~RPN(void)
{

}

static void	validExpression(const std::string input);

int RPN::solved(const std::string input)
{
	validExpression(input);

	std::stack<int> nums;

	for (unsigned int i = 0; i < input.length(); i++)
	{
		char c = input[i];

		if (c == ' ')
			continue;
		if (std::isdigit(static_cast<unsigned char>(c)))
			nums.push(c - '0');
		else
		{
			if (nums.size() < 2)
				throw std::runtime_error("\033[0;31mInsufficient operands\033[0m");

			int b = nums.top(); nums.pop();
			int a = nums.top(); nums.pop();
			int res;
			if (c == '/' && b == 0)
				throw std::runtime_error("\033[0;31mDivision by zero\033[0m");				
			switch (c)
			{
				case '+': res = a + b; break;
				case '-': res = a - b; break;
				case '*': res = a * b; break;
				case '/': res = a / b; break;
				default:
					throw std::runtime_error("\033[0;31mUnknown operator\033[0m");
			}
			nums.push(res);
		}
	}
	if (nums.size() != 1)
		throw std::runtime_error("\033[0;31mIncorrect expression\033[0m");
	return (nums.top());
}

static void	validExpression(const std::string input)
{
	for (unsigned int i = 0; i < input.length(); i++)
	{
		if (i % 2 == 0)
		{
			if (!(std::isdigit(static_cast<unsigned char>(input[i])) || input[i] == '+' || input[i] == '-'
				|| input[i] == '*' || input[i] == '/'))
				throw std::runtime_error(std::string("\033[0;31mInvalid expression. Remove: \033[0m") + input[i]);
		}
		else
		{
			if (input[i] != ' ')
				throw std::runtime_error(std::string("\033[0;31mInvalid expression. Remove: \033[0m") + input[i]);
		}
	}
}
