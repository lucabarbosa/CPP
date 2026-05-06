/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 00:44:28 by lbento            #+#    #+#             */
/*   Updated: 2026/05/06 18:47:35 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

int   main(void)
{
	{
		Weapon club = Weapon("crude spiked club");

		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");

		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	std::cout << "-----" << std::endl;
	{
		HumanB karen("Karen");
		karen.attack();
		Weapon sword = Weapon("katana");
		karen.setWeapon(sword);
		karen.attack();
	}
	{
		Weapon sword = Weapon("big knife");

		HumanA bob("Jackie", sword);
		bob.attack();
	}
	return (0);
}