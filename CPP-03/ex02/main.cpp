/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 19:22:11 by lbento            #+#    #+#             */
/*   Updated: 2026/05/13 15:13:37 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

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

	std::cout << std::endl;

	std::cout << "\033[0;33m------SCAVTRAP------\033[0m\n" << std::endl;
	ScavTrap jack("Jack");
	jack.printStatus();
	jack.attack("Psycho");
	jack.takeDamage(38);
	jack.beRepaired(8);
	jack.printStatus();
	jack.guardGate();
	jack.takeDamage(70);
	jack.beRepaired(10);
	jack.printStatus();

	std::cout << std::endl;

	std::cout << "\033[0;33m------CLAPTRAP------\033[0m\n" << std::endl;
	FragTrap lilith ("Lilith");
	lilith.printStatus();
	lilith.attack("Jack");
	lilith.takeDamage(50);
	lilith.beRepaired(20);
	lilith.printStatus();
	lilith.highFivesGuys();
	lilith.takeDamage(70);
	lilith.beRepaired(20);
	return (0);
}
