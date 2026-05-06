/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 00:46:00 by lbento            #+#    #+#             */
/*   Updated: 2026/05/06 18:44:51 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "Weapon.hpp"
#include <iostream>

HumanA::HumanA(std::string name, Weapon &weapon) : name(name), weapon(weapon)
{
	
}

HumanA::~HumanA()
{
	
}

void  HumanA::attack()
{
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}
