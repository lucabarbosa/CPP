/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 19:03:08 by lbento            #+#    #+#             */
/*   Updated: 2026/05/05 21:31:50 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int   main(int argc, char **argv)
{
	Harl harl = Harl();

	if (argc != 2)
		return (std::cout << "\033[0;33m[ Probably complaining about insignificant problems ]\033[0m" << std::endl, 1);
	harl.complain(argv[1]);
	return (0);
}