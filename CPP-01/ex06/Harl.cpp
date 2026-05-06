/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 19:03:47 by lbento            #+#    #+#             */
/*   Updated: 2026/05/06 18:50:34 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() { }

Harl::~Harl() { }

void  Harl::debug(void)
{
	std::cout << "\033[0;31m[ DEBUG ]\033[0m" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\n" << std::endl;
}

void  Harl::info(void)
{
	std::cout << "\033[0;31m[ INFO ]\033[0m" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money.\n";
	std::cout << "You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n" << std::endl;
}

void  Harl::warning(void)
{
	std::cout << "\033[0;31m[ WARNING ]\033[0m" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free.\n";
	std::cout << "I've been coming for years, whereas you started working here just last month.\n" << std::endl;
}

void  Harl::error(void)
{
	std::cout << "\033[0;31m[ ERROR ]\033[0m" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now.\n" << std::endl;
}

void  Harl::complain(std::string level)
{
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (int i = 0; i < 4; i++)
	{
		if (level == levels[i])
		{
			switch (i)
			{
				case 0:
					debug();
					// falls through
				case 1:
					info();
					// falls through
				case 2:
					warning();
					// falls through
				case 3:
					error();
					// falls through
				default:
					break;
			}
			return ;
		}
	}
	std::cout << "\033[0;33m[ Probably complaining about insignificant problems ]\033[0m" << std::endl;
}
