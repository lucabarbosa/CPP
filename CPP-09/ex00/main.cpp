/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 00:49:35 by lbento            #+#    #+#             */
/*   Updated: 2026/07/13 22:49:56 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int   main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "\033[0;31mExpected just one argument.\033[0m" << std::endl;
		std::cerr << "\033[0;31mUse ./btc <file>\033[0m" << std::endl;
		return (1);
	}
	{
		BitcoinExchange btc;
		try
		{
			btc.loadInput("data.csv");
			btc.processInput(argv[1]);
		}
		catch (const std::exception &e)
		{
			std::cerr << "\033[1;31mError: \033[0m" << e.what() << std::endl;
			return (1);
		}
	}
	return (0);
}
