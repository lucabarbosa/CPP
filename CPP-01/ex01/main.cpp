/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 09:40:09 by lbento            #+#    #+#             */
/*   Updated: 2026/05/06 18:56:15 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"
#include "Zombie.hpp"

int   main(void)
{
	std::cout << "Creating and deleting zombie horde:" << std::endl;
	Zombie *horde = zombieHorde(10, "Zoombies horde");
	if (!horde)
		return (1);
	for(int i = 0; i < 10; i++)
		horde[i].announce();
	delete []horde;
	return (0);
}
