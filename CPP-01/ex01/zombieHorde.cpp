/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 23:22:07 by lbento            #+#    #+#             */
/*   Updated: 2026/05/06 18:55:07 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

Zombie* zombieHorde(int N, std::string name)
{
	Zombie   *horde = new Zombie[N];

	if (N <= 0)
		return (NULL);
	for (int i = 0; i < N; i++)
		horde[i].set_name(name);
	return (horde);
}
