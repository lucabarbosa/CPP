/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 00:46:00 by lbento            #+#    #+#             */
/*   Updated: 2026/05/05 13:22:13 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "Weapon.hpp"
#include <iostream>

HumanA::HumanA(std::string name, Weapon &weapon) : name(name), weapon(weapon) { }

HumanA::~HumanA() {}

void	HumanA::setWeapon(Weapon &weapon)
{
	this->weapon = weapon;
}

void  HumanA::attack()
{
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}
