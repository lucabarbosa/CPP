/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 18:03:12 by lbento            #+#    #+#             */
/*   Updated: 2026/06/10 23:28:30 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <climits>
#include <limits>
#include <iomanip>

class ScalarConverter
{
	private:
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter &operator=(const ScalarConverter &other);
		~ScalarConverter(void);
		static void	convertChar(int value);
		static void	convertInt(int value);
		static void	convertFloat(double value);
		static void	convertDouble(double value);
	public:
		static void	convert(const std::string &literal);
};

#endif