/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 10:39:54 by lbento            #+#    #+#             */
/*   Updated: 2026/05/20 20:52:54 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void	print_title(std::string title);

int   main(void)
{
	{
		print_title("Testing constructors");
		try
		{
			Bureaucrat polvo("Polvo", 42);
			std::cout << polvo << std::endl;
		}
		catch(const std::exception &e)
		{
			std::cout << "\033[0;31mGrade out of range expected: \033[0m" << e.what() << std::endl;
		}
	}
//----------------
	{
		print_title("TESTING HIGH GRADE");
		try
		{
			Bureaucrat polvo("Polvo", 1);
			
			std::cout << "\033[0;34m• Decrement grade \033[0m-" << std::endl;
			polvo.decrementGrade();
			
			std::cout << "\033[0;36m• Increment grade \033[0m+" << std::endl;
			polvo.incrementGrade();
			
			std::cout << "\033[0;36m• Increment grade \033[0m+" << std::endl;
			polvo.incrementGrade();

			std::cout << "\033[0;34m• Decrement grade \033[0m-" << std::endl;
			polvo.decrementGrade();

			std::cout << polvo << std::endl;
		}
		catch(const std::exception &e)
		{
			std::cout << "\033[0;31mGrade out of expected range: \033[0m" << e.what() << std::endl;
		}
	}
//----------------
	{
		print_title("TESTING LOW GRADE");
		try
		{
			Bureaucrat polvo("Polvo", 150);
			
			std::cout << "\033[0;36m• Increment grade \033[0m+" << std::endl;
			polvo.incrementGrade();
			
			std::cout << "\033[0;36m• Increment grade \033[0m+" << std::endl;
			polvo.incrementGrade();

			std::cout << "\033[0;34m• Decrement grade \033[0m-" << std::endl;
			polvo.decrementGrade();
			
			std::cout << "\033[0;34m• Decrement grade \033[0m-" << std::endl;
			polvo.decrementGrade();
			
			std::cout << "\033[0;34m• Decrement grade \033[0m-" << std::endl;
			polvo.decrementGrade();

			std::cout << polvo << std::endl;
		}
		catch(const std::exception &e)
		{
			std::cout << "\033[0;31mGrade out of expected range: \033[0m" << e.what() << std::endl;
		}
	}
	//----------------
	{
		print_title("TESTING LOW GRADE");
		try
		{
			Bureaucrat polvo("Polvo", 1);
			
			for (int i = 150; i > 0; i--)
			{
				std::cout << "\033[0;34m• Decrement grade \033[0m-" << std::endl;
				polvo.decrementGrade();
				std::cout << polvo << std::endl;
			}
			
			std::cout << polvo << std::endl;
		}
		catch(const std::exception &e)
		{
			std::cout << "\033[0;31mGrade out of expected range: \033[0m" << e.what() << std::endl;
		}
	}
}

void	print_title(std::string title)
{
	std::cout  << "\n\033[1;32m---------- " << title << " ----------\033[0m" << std::endl;
}
