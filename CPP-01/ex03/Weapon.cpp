/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 00:45:24 by lbento            #+#    #+#             */
/*   Updated: 2026/05/05 12:51:11 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std:: string type)
{
   this->type = type;
}

Weapon::~Weapon() {}

std::string Weapon::getType(void)
{
   return (this->type);
}

void  Weapon::setType(std::string type)
{
   this->type = type;
}
