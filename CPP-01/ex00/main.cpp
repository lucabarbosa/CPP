/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 09:40:09 by lbento            #+#    #+#             */
/*   Updated: 2026/05/04 22:49:47 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"
#include "Zombie.hpp"

int   main(void)
{
	Zombie *allocated = newZombie("Marcio(Heap)");
	allocated->announce();
	delete allocated;
	randomChump("José(Stack)");
	return (0);
}
