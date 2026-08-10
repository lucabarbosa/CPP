/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 18:03:04 by lbento            #+#    #+#             */
/*   Updated: 2026/08/10 15:58:54 by lbento           ###   ########.fr       */
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
		std::cout << "\033[0;32mchar:\033[0;31m Impossible \033[0m" << std::endl;
	else if ((static_cast<int>(value) >= 0 && static_cast<int>(value) <= 31) || static_cast<int>(value) == 127)
		std::cout << "\033[0;32mchar:\033[0;31m Not displayable\033[0m" << std::endl;
	else
		std::cout << "\033[0;32mchar:\033[0m '" << static_cast<char>((int)value) << "'" << std::endl;
}

void	ScalarConverter::convertInt(double value)
{
	if (value > static_cast<double>(INT_MAX) || value < static_cast<double>(INT_MIN))
		std::cout << "\033[0;33mint:\033[0;31m Impossible \033[0m" << std::endl;
	else
		std::cout << "\033[0;33mint:\033[0m " << static_cast<int>(value) << std::endl;
}

void	ScalarConverter::convertFloat(double value)
{
	std::cout << std::fixed << std::setprecision(1);
	if (std::isnan(value))
        std::cout << "\033[0;34mfloat:\033[0m nanf" << std::endl;
   else if (std::isinf(value))
	{
		if (value > 0)
			std::cout << "\033[0;34mfloat:\033[0m +inff" << std::endl;
		else
			std::cout << "\033[0;34mfloat:\033[0m -inff" << std::endl;
	}
	else
		std::cout << "\033[0;34mfloat:\033[0m " << static_cast<float>(value) << "f" << std::endl;
}
void	ScalarConverter::convertDouble(double value)
{
	std::cout << std::fixed << std::setprecision(1);
	if (std::isnan(value))
		std::cout << "\033[0;35mdouble:\033[0m nan" << std::endl;
	else if (std::isinf(value))
	{
		if (value > 0)
			std::cout << "\033[0;35mdouble:\033[0m +inf" << std::endl;
		else
			std::cout << "\033[0;35mdouble:\033[0m -inf" << std::endl;
	}
	else
		std::cout << "\033[0;35mdouble:\033[0m " << value << std::endl;
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
			std::cout << "\033[0;32mchar:\033[0;31m Impossible \033[0m\n"
			<< "\033[0;33mint:\033[0;31m Impossible \033[0m\n"
			<< "\033[0;34mfloat:\033[0;31m Impossible \033[0m\n"
			<< "\033[0;35mdouble:\033[0;31m Impossible \033[0m" << std::endl;
			return ;
		}
	}
	
	if (std::isnan(value) || std::isinf(value))
		std::cout << "\033[0;32mchar:\033[0;31m Impossible \033[0m\n" << "\033[0;33mint:\033[0;31m Impossible \033[0m" << std::endl;
	else
	{
		convertChar(value);
		convertInt(value);
	}
	convertFloat(value);
	convertDouble(value);
}
