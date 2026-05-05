/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 09:41:18 by lbento            #+#    #+#             */
/*   Updated: 2026/05/04 22:35:54 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"
#include "Zombie.hpp"

void  randomChump(std::string name)
{
   Zombie chump_zombie = Zombie(name);
   chump_zombie.announce();
}
