/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 00:53:52 by lbento            #+#    #+#             */
/*   Updated: 2026/07/22 23:40:35 by lbento           ###   ########.fr       */
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
		}
		catch(const std::exception &e)
		{
			std::cerr << "\033[1;31mError:" << e.what() << std::endl;
			return (1);
		}
	}
	return (0);
}
