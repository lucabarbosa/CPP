/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 23:22:07 by lbento            #+#    #+#             */
/*   Updated: 2026/05/05 00:06:16 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

Zombie* zombieHorde(int N, std::string name)
{
	Zombie   *horde = new Zombie[N];

	for (int i = 0; i < N; i++)
		horde[i].set_name(name);
	return (horde);
}
