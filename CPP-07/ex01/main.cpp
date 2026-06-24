/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 19:27:17 by lbento            #+#    #+#             */
/*   Updated: 2026/06/24 20:54:03 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int   main(void)
{
	{
		std::cout << "\033[3;34m Tests with int array" << std::endl;
		int array[5] = {1, 2, 3, 4, 5};
		iter(array, 5, printValue<int>);
		std::cout << "\033[0;34m Adding one:" << std::endl;
		iter(array, 5, addElement<int>);
		iter(array, 5, printValue<int>);
		std::cout << "\033[0m" << std::endl;
	}
	{
		std::cout << "\033[3;35m Tests with double array" << std::endl;
		double array[5] = {1.2, 2.3, 3.4, 4.5, 5.1};
		iter(array, 5, printValue<double>);
		std::cout << "\033[0;35m Adding one:" << std::endl;
		iter(array, 5, addElement<double>);
		iter(array, 5, printValue<double>);
		std::cout << "\033[0m" << std::endl;
	}
	{
		std::cout << "\033[3;36m Tests with char array" << std::endl;
		char array[3] = {'a', 'b', 'c'};
		iter(array, 3, printValue<char>);
		std::cout << "\033[0m" << std::endl;
	}
	{
		std::cout << "\033[3;33m Tests with string array" << std::endl;
		std::string array[3] = {"One", "Two", "Three"};
		iter(array, 3, printValue<std::string>);
		std::cout << "\033[0m" << std::endl;
	}
	{
		std::cout << "\033[3;33m Tests with CONST string array" << std::endl;
		std::string const array[3] = {"One", "Two", "Three"};
		iter(array, 3, printValue<const std::string>);
		std::cout << "\033[0m" << std::endl;
	}
	return (0);
}
