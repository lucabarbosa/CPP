/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 00:53:52 by lbento            #+#    #+#             */
/*   Updated: 2026/07/26 00:49:02 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int   main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "\033[1;31mError:\033[0;31m Expects a sequence of integers.\033[0m" << std::endl;
		return (1);
	}
	{
		PmergeMe PM;
		try
		{
			PM.checkNumbers(argc, argv);
			std::cout << "\033[0;35mBefore:  ";
			PM.printNum();
			std::cout << "\033[0;34mAfter :  ";
			PM.printNum();
			PM.printTime();
		}
		catch(const std::exception &e)
		{
			std::cerr << "\033[1;31mError:" << e.what() << std::endl;
			return (1);
		}
	}
	return (0);
}
