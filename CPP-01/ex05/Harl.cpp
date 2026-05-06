/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 19:03:47 by lbento            #+#    #+#             */
/*   Updated: 2026/05/05 21:01:12 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() { }

Harl::~Harl() { }

void  Harl::debug(void)
{
   std::cout << "\033[0;36mDEBUG ->\033[0m I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void  Harl::info(void)
{
   std::cout << "\033[0;36mINFO ->\033[0m I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void  Harl::warning(void)
{
   std::cout << "\033[0;36mWARNING ->\033[0m I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month." << std::endl;
}

void  Harl::error(void)
{
   std::cout << "\033[0;36mERROR ->\033[0m This is unacceptable! I want to speak to the manager now." << std::endl;
}

void  Harl::complain(std::string level)
{
   std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

  	void  (Harl::*complaining[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
   
   for (int i = 0; i < 4; i++)
   {
      if (level == levels[i])
      {
         (this->*complaining[i])();
         return ;
      }
   }
}
