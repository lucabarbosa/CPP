/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 19:03:08 by lbento            #+#    #+#             */
/*   Updated: 2026/05/05 19:29:11 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int   main(void)
{
	Harl harl = Harl();
	
	harl.complain("DEBUG");
	harl.complain("INFO");
   harl.complain("WARNING");
   harl.complain("ERROR");
}