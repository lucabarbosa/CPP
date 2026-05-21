/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 10:39:54 by lbento            #+#    #+#             */
/*   Updated: 2026/05/21 15:15:06 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

void	print_title(std::string title);

int   main(void)
{
	{
		print_title("Testing constructors from intern");
		try
		{
			Intern intern;
			AForm *tree;
			Bureaucrat putin("Putin", 1);
			
			putin.executeForm(*tree);
			tree = intern.makeForm("ShrubberyCreationForm", "Home");
		}
		catch(const std::exception &e)	
		{
			std::cout << "\033[0;31mGrade out of range expected: \033[0m" << e.what() << std::endl;
		}
	}
//----------------
	// {
	// 	print_title("Testing constructors without signing");
	// 	try
	// 	{
	// 		Bureaucrat putin("Putin", 1);
	// 		ShrubberyCreationForm tree("tree");

	// 		putin.executeForm(tree);
	// 	}
	// 	catch(const std::exception &e)
	// 	{
	// 		std::cout << "\033[0;31mGrade out of range expected: \033[0m" << e.what() << std::endl;
	// 	}
	// }
//----------------
	return (0);
}

void	print_title(std::string title)
{
	std::cout  << "\n\033[1;32m---------- " << title << " ----------\033[0m" << std::endl;
}
