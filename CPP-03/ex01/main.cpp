/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 19:22:11 by lbento            #+#    #+#             */
/*   Updated: 2026/05/13 14:23:10 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int   main(void)
{
	// std::cout << "\033[0;33m------CLAPTRAP------\033[0m\n" << std::endl;
	// ClapTrap axton("Axton");
	// axton.printStatus();
	// axton.attack("Loader Bots");
	// axton.takeDamage(3);
	// axton.beRepaired(5);
	// axton.takeDamage(4);
	// axton.takeDamage(1);
	// axton.printStatus();
	// axton.attack("Loader Bots");
	// axton.beRepaired(5);
	// axton.beRepaired(2);
	// axton.attack("Loader Bots");
	// axton.attack("Loader Bots");
	// axton.attack("Loader Bots");
	// axton.attack("Loader Bots");
	// axton.takeDamage(8);
	// axton.attack("Loader Bots");
	// axton.printStatus();
	// axton.beRepaired(4);
	// axton.attack("Loader Bots");

	std::cout << "\033[0;33m------SCAVTRAP------\033[0m\n" << std::endl;
	ScavTrap jack("Jack");
	jack.printStatus();
	jack.attack("Psycho");
	jack.takeDamage(38);
	jack.attack("Psycho");
	jack.takeDamage(50);
	jack.printStatus();
	jack.beRepaired(48);
	jack.attack("Psycho");
	jack.beRepaired(10);
	jack.printStatus();
	jack.takeDamage(70);
	jack.beRepaired(10);
	jack.guardGate();
	return (0);
}
