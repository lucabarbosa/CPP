/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 18:03:04 by lbento            #+#    #+#             */
/*   Updated: 2026/06/11 09:41:22 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void)
{
	
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	(void)other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other;
	return (*this);
}

ScalarConverter::~ScalarConverter(void)
{

}

void	ScalarConverter::convertChar(double value)
{
	if (value < 0 || value > 127)
		std::cout << "char: Impossible" << std::endl;
	else if (((int)value >= 0 && (int)value <= 31) || (int)value == 127)
		std::cout << "char: Not displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>((int)value) << "'" << std::endl;
}

void	ScalarConverter::convertInt(double value)
{
	if (value > static_cast<double>(INT_MAX) || value < static_cast<double>(INT_MIN))
		std::cout << "int: Impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(value) << std::endl;
}

void	ScalarConverter::convertFloat(double value)
{
	std::cout << std::fixed << std::setprecision(1);
	if (std::isnan(value))
        std::cout << "float: nanf" << std::endl;
   else if (std::isinf(value))
	{
		if (value > 0)
			std::cout << "float: +inff" << std::endl;
		else
			std::cout << "float: -inff" << std::endl;
	}
	else
		std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
}
void	ScalarConverter::convertDouble(double value)
{
	std::cout << std::fixed << std::setprecision(1);
	if (std::isnan(value))
		std::cout << "double: nan" << std::endl;
	else if (std::isinf(value))
	{
		if (value > 0)
			std::cout << "float: +inff" << std::endl;
		else
			std::cout << "float: -inff" << std::endl;
	}
	else
		std::cout << "double: " << value << std::endl;
}

void ScalarConverter::convert(const std::string &literal)
{
	double value = 0.0;

	if (!std::isdigit(literal[0]) && literal.length() == 1)
		value = static_cast<int>(literal[0]);
	else
	{
		char *end;
		value = std::strtod(literal.c_str(), &end);
		if (!((end[0] == 'f' && end[1] == '\0') || end[0] == '\0'))
		{
			std::cout << "char: Impossible\n" << "int: Impossible\n" << "float: Impossible\n" << "double: Impossible\n" << std::endl;
			return ;
		}
	}
	
	if (std::isnan(value) || std::isinf(value))
		std::cout << "char: Impossible.\n" << "int: Impossible." << std::endl;
	else
	{
		convertChar(value);
		convertInt(value);
	}
	convertFloat(value);
	convertDouble(value);
}
