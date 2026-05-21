/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 10:39:54 by lbento            #+#    #+#             */
/*   Updated: 2026/05/21 18:21:38 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"
#include <ctime>

void	print_title(std::string title);

int   main(void)
{
	std::srand(std::time(NULL));
	{
		print_title("Testing intern for each form");
		try
		{
			Bureaucrat boss("Boss", 1);
			Intern intern;
			AForm *form;
			
			
			form = intern.makeForm("ShrubberyCreationForm", "Tree");
			boss.signForm(*form);
			boss.executeForm(*form);
			delete form;
			std::cout << "-----" << std::endl;
			
			form = intern.makeForm("RobotomyRequestForm", "Bender");
			boss.signForm(*form);
			boss.executeForm(*form);
			delete form;
			std::cout << "-----" << std::endl;
			
			form = intern.makeForm("PresidentialPardonForm", "Arthur");
			boss.signForm(*form);
			boss.executeForm(*form);
			delete form;
			std::cout << "-----" << std::endl;
			
			form = intern.makeForm("Non-existentForm", "target");
			if (form)
				delete form;
		}
		catch(const std::exception &e)
		{
			std::cout << "\033[0;31mGrade out of range expected: \033[0m" << e.what() << std::endl;
		}
	}
//----------------
	{
		print_title("Testing intern with Bureaucrat stream");
		try
		{
			Intern intern;
			Bureaucrat boss("Boss", 1);
			AForm *tree = intern.makeForm("ShrubberyCreationForm", "Tree");
			if (tree)
			{
				boss.signForm(*tree);
				boss.executeForm(*tree);
				delete tree;
			}
			else
				std::cout << "Allocation error.";
		}
		catch(const std::exception &e)	
		{
			std::cout << "\033[0;31mGrade out of range expected: \033[0m" << e.what() << std::endl;
		}
	}
//----------------
	{
		print_title("Testing Intern without signing");
		try
		{
			Intern intern;
			Bureaucrat boss("Boss", 1);
			AForm *form = intern.makeForm("ShrubberyCreationForm", "Tree");
			if (form)
			{
				boss.executeForm(*form);
				delete form;
			}
		}
		catch(const std::exception &e)
		{
			std::cout << "\033[0;31mGrade out of range expected: \033[0m" << e.what() << std::endl;
		}
	}
//----------------
	{
		print_title("Testing Intern with low grade");
		try
		{
			Intern intern;
			Bureaucrat boss("Boss", 150);
			AForm *form = intern.makeForm("PresidentialPardonForm", "Arthur");
			if (form)
			{
				boss.signForm(*form);
				boss.executeForm(*form);
				delete form;
			}
		}
		catch(const std::exception &e)
		{
			std::cout << "\033[0;31mGrade out of range expected: \033[0m" << e.what() << std::endl;
		}
	}
//----------------
	{
		print_title("Testing Intern with low grade");
		try
		{
			Intern intern;
			Bureaucrat signer("Signer", 72);
			Bureaucrat executor("Executor", 45);
			AForm *form = intern.makeForm("RobotomyRequestForm", "Bender");
			if (form)
			{
   			signer.signForm(*form);
				executor.executeForm(*form);
				delete form;
			}
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
