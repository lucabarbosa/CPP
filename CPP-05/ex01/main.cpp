/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 10:39:54 by lbento            #+#    #+#             */
/*   Updated: 2026/05/20 21:19:31 by lbento           ###   ########.fr       */
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
			Form polvo("Polvo", 42, 42);
			std::cout << polvo << std::endl;
		}
		catch(const std::exception &e)
		{
			std::cout << "\033[0;31mGrade out of range expected: \033[0m" << e.what() << std::endl;
		}
	}
//----------------
	{
		print_title("Testing 0 signed grade");
		try
		{
			Form polvo("Polvo", 0, 42);
			std::cout << polvo << std::endl;
		}
		catch(const std::exception &e)
		{
			std::cout << "\033[0;31mGrade out of range expected: \033[0m" << e.what() << std::endl;
		}
	}
//----------------
	{
		print_title("Testing 151 signed grade");
		try
		{
			Form polvo("Polvo", 151, 42);
			std::cout << polvo << std::endl;
		}
		catch(const std::exception &e)
		{
			std::cout << "\033[0;31mGrade out of range expected: \033[0m" << e.what() << std::endl;
		}
	}
//----------------
	{
		print_title("Testing 0 exec grade");
		try
		{
			Form polvo("Polvo", 42, 0);
			std::cout << polvo << std::endl;
		}
		catch(const std::exception &e)
		{
			std::cout << "\033[0;31mGrade out of range expected: \033[0m" << e.what() << std::endl;
		}
	}
//----------------
	{
		print_title("Testing 151 exec grade");
		try
		{
			Form polvo("Polvo", 42, 151);
			std::cout << polvo << std::endl;
		}
		catch(const std::exception &e)
		{
			std::cout << "\033[0;31mGrade out of range expected: \033[0m" << e.what() << std::endl;
		}
	}
//----------------
	{
		print_title("Testing signed");
		try
		{
			Bureaucrat bureaucrat("Bureaucrat", 1);
			Form polvo("Polvo", 42, 1);
			std::cout << "\033[0;34mTry to sign with grade \033[0m" << bureaucrat.getGrade() << std::endl;
			bureaucrat.signForm(polvo);
			std::cout << polvo << std::endl;
		}
		catch(const std::exception &e)
		{
			std::cout << "\033[0;31mGrade out of range expected: \033[0m" << e.what() << std::endl;
		}
	}
//----------------
	{
		print_title("Testing signed while increment and decrement");
		try
		{
			Bureaucrat bureaucrat("Bureaucrat", 42);
			Form polvo("Polvo", 42, 1);
			std::cout << "\033[0;34mTry to sign with grade \033[0m" << bureaucrat.getGrade() << std::endl;
			bureaucrat.signForm(polvo);
			std::cout << polvo << std::endl;
			bureaucrat.decrementGrade();
			std::cout << "\033[0;34mTry to sign with grade \033[0m" << bureaucrat.getGrade() << std::endl;
			bureaucrat.signForm(polvo);
			std::cout << polvo << std::endl;
		}
		catch(const std::exception &e)
		{
			std::cout << "\033[0;31mGrade out of range expected: \033[0m" << e.what() << std::endl;
		}
	}
}

void	print_title(std::string title)
{
	std::cout  << "\n\033[1;32m---------- " << title << " ----------\033[0m" << std::endl;
}
