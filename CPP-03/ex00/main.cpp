/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 19:22:11 by lbento            #+#    #+#             */
/*   Updated: 2026/05/13 15:14:19 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int   main(void)
{
	std::cout << "\033[0;33m------CLAPTRAP------\033[0m\n" << std::endl;
	ClapTrap axton("Axton");

	axton.printStatus();
	axton.attack("Loader Bots");
	axton.takeDamage(5);
	axton.beRepaired(3);
	axton.takeDamage(6);
	axton.printStatus();
	axton.attack("Loader Bots");
	axton.beRepaired(1);
	axton.attack("Loader Bots");
	axton.beRepaired(1);
	axton.attack("Loader Bots");
	axton.beRepaired(1);
	axton.attack("Loader Bots");
	axton.beRepaired(1);
	axton.beRepaired(4);
	axton.attack("Loader Bots");
	axton.takeDamage(10);
	axton.takeDamage(2);
	axton.printStatus();
	return (0);
}
