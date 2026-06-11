/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 18:04:15 by lbento            #+#    #+#             */
/*   Updated: 2026/06/10 23:25:00 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int   main (int argc, char **argv)
{
	if (argc == 2)
		ScalarConverter::convert(argv[1]);
	else
	{
		std::cout << "Wrong format. Try ./converter <literal>" << std::endl;
		return (1);
	}
	return (0);
}
