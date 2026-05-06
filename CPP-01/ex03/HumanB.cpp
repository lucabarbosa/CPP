/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 00:48:04 by lbento            #+#    #+#             */
/*   Updated: 2026/05/06 18:31:24 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include "Weapon.hpp"
#include <iostream>

HumanB::HumanB(std::string name)
{
	this->name = name;
	this->weapon = NULL;
}

HumanB::~HumanB()
{
	
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}

void  HumanB::attack()
 {
	if (!weapon)
		std::cout << name << " attacks " << "unarmed" << std::endl;
	else
		std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}