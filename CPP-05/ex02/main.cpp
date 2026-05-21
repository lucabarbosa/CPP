/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 10:39:54 by lbento            #+#    #+#             */
/*   Updated: 2026/05/21 13:54:34 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <ctime>

void	print_title(std::string title);

int   main(void)
{
	std::srand(std::time(NULL));

	{
		print_title("Testing constructors and sign");
		try
		{
			Bureaucrat putin("Putin", 1);
			ShrubberyCreationForm tree("tree");
			
			putin.signForm(tree);
			putin.executeForm(tree);
		}
		catch(const std::exception &e)
		{
			std::cout << "\033[0;31mGrade out of range expected: \033[0m" << e.what() << std::endl;
		}
	}
//----------------
	{
		print_title("Testing constructors without signing");
		try
		{
			Bureaucrat putin("Putin", 1);
			ShrubberyCreationForm tree("tree");

			putin.executeForm(tree);
		}
		catch(const std::exception &e)
		{
			std::cout << "\033[0;31mGrade out of range expected: \033[0m" << e.what() << std::endl;
		}
	}
//----------------
	{
		print_title("Testing with low grade");
		try
		{
			Bureaucrat putin("Putin", 150);
			ShrubberyCreationForm tree("tree");
			
			putin.signForm(tree);
			putin.executeForm(tree);
		}
		catch(const std::exception &e)
		{
			std::cout << "\033[0;31mGrade out of range expected: \033[0m" << e.what() << std::endl;
		}
	}
//----------------
	{
		print_title("Testing robotomy");
		try
		{
			Bureaucrat putin("Putin", 1);
			RobotomyRequestForm bender("Bender");

			putin.signForm(bender);
			for (int i = 0; i < 4; i++)
			{
				putin.executeForm(bender);
				std::cout << "-----" << std::endl;
			}
		}
		catch(const std::exception &e)
		{
			std::cout << "\033[0;31mGrade out of range expected: \033[0m" << e.what() << std::endl;
		}
	}
//----------------
	{
		print_title("Testing presidential");
		try
		{
			Bureaucrat putin("Putin", 1);
			PresidentialPardonForm president("President");

			putin.signForm(president);
			putin.executeForm(president);
		}
		catch(const std::exception &e)
		{
			std::cout << "\033[0;31mGrade out of range expected: \033[0m" << e.what() << std::endl;
		}
	}
//----------------
	{
		print_title("Edge cases");
		try
		{
			Bureaucrat signer("Signer", 72);
			Bureaucrat executor("Executor", 46);
			RobotomyRequestForm bender("Bender");

			signer.signForm(bender);
			executor.executeForm(bender);
		}
		catch(const std::exception &e)
		{
			std::cout << "\033[0;31mGrade out of range expected: \033[0m" << e.what() << std::endl;
		}
	}
	return (0);
}

void	print_title(std::string title)
{
	std::cout  << "\n\033[1;32m---------- " << title << " ----------\033[0m" << std::endl;
}
