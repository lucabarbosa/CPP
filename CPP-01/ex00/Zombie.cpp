/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 10:09:36 by lbento            #+#    #+#             */
/*   Updated: 2026/05/04 22:47:09 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"
#include "Zombie.hpp"

Zombie::Zombie()
{
   this->name = "Zombie nameless";
}

Zombie::Zombie(std::string name)
{ 
   this->name = name;
}

Zombie::~Zombie(void)
{
   std::cout << name << ": die!\n";
}

void Zombie::announce(void)
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void  Zombie::set_name(std::string name)
{
   this->name = name;
}

std::string Zombie::get_name(void)
{
   return(this->name);
}
