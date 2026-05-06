/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 22:06:49 by lbento            #+#    #+#             */
/*   Updated: 2026/05/06 18:10:28 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int   main (void)
{
	PhoneBook phonebook;
	std::string cmd;
	std::cout << "\033[0;36m* Welcome to your Phonebook *\n\033[0m";
	while (cmd != "EXIT")
	{
		std::cout << "\033[0;32mType Command (ADD, SEARCH, EXIT): \033[0m";
		std::getline(std::cin, cmd);
		if (std::cin.eof())
		{
			std::cout << "\n\033[0;31mEOF detected. Returning to main menu.\n\033[0m";
			std::cin.clear();
			return (0);
		}
		else if (cmd == "ADD")
			phonebook.add_contact();
		else if (cmd == "SEARCH")
		{
			if (phonebook.get_total_contacts() == 0)
				std::cout << "\033[0;33mNo contacts.\033[0m" << std::endl;
			else
				phonebook.search();
		}
		else if (cmd == "EXIT")
			break ;
		else
		{
			std::cout << "\033[0;31m\"\033[0m" << cmd << "\033[0;31m\"\033[0m";
			std::cout << "\033[0;31m is not valid command.\n\033[0m";
		}
	}
	return (0);
}
