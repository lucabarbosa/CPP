/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 16:37:17 by lbento            #+#    #+#             */
/*   Updated: 2026/06/28 10:54:39 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int	main(void)
{
	{
		std::cout << "\033[1;33mList tests\033[0m" << std::endl;
		std::list <int> list_ints;
		list_ints.push_back(10);
		list_ints.push_back(20);
		list_ints.push_back(30);
		try
		{
			std::cout << "\033[4;33mList Values: {10, 20, 30}\033[0m" << std::endl;
			std::cout << "\033[0;33mSearching (10): \033[0m" << *::easyfind(list_ints, 10) << std::endl;
			std::cout << "\033[0;33mSearching (20): \033[0m" << *::easyfind(list_ints, 20) << std::endl;
			std::cout << "\033[0;33mSearching (5): \033[0m" << *::easyfind(list_ints, 5) << std::endl;
		}
		catch(const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}		
	}
	{
		std::cout << "\n\033[1;34mVector tests\033[0m" << std::endl;
		std::vector <int> vect_ints;
		vect_ints.push_back(100);
		vect_ints.push_back(200);
		vect_ints.push_back(300);
		try
		{
			std::cout << "\033[4;34mVector Values: {100, 200, 300}\033[0m" << std::endl;
			std::cout << "\033[0;34mSearching (100): \033[0m" << *::easyfind(vect_ints, 100) << std::endl;
			std::cout << "\033[0;34mSearching (200): \033[0m" << *::easyfind(vect_ints, 200) << std::endl;
			std::cout << "\033[0;34mSearching (50): \033[0m" << *::easyfind(vect_ints, 50) << std::endl;
		}
		catch(const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}		
	}
	{
		std::cout << "\n\033[1;36mDeque tests\033[0m" << std::endl;
		std::deque <int> deque_ints;
		deque_ints.push_back(-10);
		deque_ints.push_back(-20);
		deque_ints.push_back(-30);
		try
		{
			std::cout << "\033[4;36mDeque Values: {-10, -20, -30}\033[0m" << std::endl;
			std::cout << "\033[0;36mSearching (-10): \033[0m" << *::easyfind(deque_ints, -10) << std::endl;
			std::cout << "\033[0;36mSearching (-20): \033[0m" << *::easyfind(deque_ints, -20) << std::endl;
			std::cout << "\033[0;36mSearching (-50): \033[0m" << *::easyfind(deque_ints, -50) << std::endl;
		}
		catch(const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}		
	}
	return (0);
}
