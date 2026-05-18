/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 10:39:54 by lbento            #+#    #+#             */
/*   Updated: 2026/05/18 01:56:13 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

void	print_title(std::string title);

int   main(void)
{
	{
		print_title("Testing constructors");
		try
		{
			Form taxadd("Taxadd", 42, 42);
			std::cout << taxadd << std::endl;
		}
		catch(const std::exception &e)
		{
			std::cout << "\033[0;31mGrade out of range expected \033[0m" << e.what() << std::endl;
		}
	}
//----------------
}

void	print_title(std::string title)
{
	std::cout  << "\n\033[1;32m---------- " << title << " ----------\033[0m" << std::endl;
}
