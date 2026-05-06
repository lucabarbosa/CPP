/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 09:40:09 by lbento            #+#    #+#             */
/*   Updated: 2026/05/06 18:33:06 by lbento           ###   ########.fr       */
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
