/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 09:55:47 by lbento            #+#    #+#             */
/*   Updated: 2026/05/06 18:32:45 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
#define ZOMBIE_H

#include "Zombie.hpp"

Zombie	*newZombie(std::string name);
void		randomChump(std::string name);
Zombie* zombieHorde(int N, std::string name);

#endif