/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 19:22:11 by lbento            #+#    #+#             */
/*   Updated: 2026/05/13 12:56:45 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int   main(void)
{
	std::cout << "\033[0;33m------CLAPTRAP------\033[0m\n" << std::endl;
	ClapTrap jack("Jack");
	jack.printStatus();
	jack.attack("Psycho");
	jack.takeDamage(3);
	jack.beRepaired(5);
	jack.takeDamage(4);
	jack.takeDamage(1);
	jack.printStatus();
	jack.attack("Psycho");
	jack.beRepaired(5);
	jack.beRepaired(2);
	jack.attack("Psycho");
	jack.attack("Psycho");
	jack.attack("Psycho");
	jack.attack("Psycho");
	jack.takeDamage(8);
	jack.attack("Psycho");
	jack.printStatus();
	jack.beRepaired(4);
	jack.attack("Psycho");
	return (0);
}
