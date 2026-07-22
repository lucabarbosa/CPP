/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 00:51:29 by lbento            #+#    #+#             */
/*   Updated: 2026/07/22 00:44:17 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "\033[0;31mExpected just one argument.\033[0m" << std::endl;
		std::cerr << "\033[0;31mUse ./RPN <inverted math expression>\033[0m" << std::endl;
		return (1);
	}
	{
		RPN rpn;
		try
		{
			int	result;
			result = rpn.solved(argv[1]);
			std::cout << "\033[0;32m" << result << "\033[0m" << std::endl;
		}
		catch(const std::exception &e)
		{
			std::cerr << "\033[1;31mError: \033[0m" << e.what() << std::endl;
		}
		
	}
	return (0);
}
