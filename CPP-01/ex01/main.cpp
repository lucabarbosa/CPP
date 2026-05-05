/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 09:40:09 by lbento            #+#    #+#             */
/*   Updated: 2026/05/05 00:22:14 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"
#include "Zombie.hpp"

int   main(void)
{
	std::cout << "Creating and deleting horde with 10 zombies:" << std::endl;
	Zombie *horde = zombieHorde(10, "Zoombies horde");
	for(int i = 0; i < 10; i++)
		horde[i].announce();
	delete []horde;
	return (0);
}
