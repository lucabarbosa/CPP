/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 09:40:01 by lbento            #+#    #+#             */
/*   Updated: 2026/06/30 00:50:14 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int	main(void)
{
	{
		std::cout << "\033[4;33m- Subject Tests -\033[0m" << std::endl;
		try
		{
			Span sp = Span(5);
			sp.addNumber(6);
			sp.addNumber(3);
			sp.addNumber(17);
			sp.addNumber(9);
			sp.addNumber(11);
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << "\n\033[4;37m- Testing limits -\033[0m" << std::endl;
	{
		try
		{
			std::cout << "\n\033[1;33mTEST WITH ZERO\033[0m" << std::endl;
			std::cout << "\033[0;33mCreating:\033[0m Span(0)" << std::endl;
			Span sp = Span(0);
			std::cout << "\033[0;33mTrying add number\033[0m: sp.addNumber(10)" << std::endl;
			sp.addNumber(10);
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
		std::cout << "\n\033[1;34mTEST WITH 1 NUMBER\033[0m" << std::endl;
		std::cout << "\033[0;34mCreating:\033[0m Span(1)" << std::endl;
		Span sp = Span(1);
		std::cout << "\033[0;34mTrying add number\033[0m: sp.addNumber(10)" << std::endl;
		sp.addNumber(10);
		try
		{
			std::cout << "\033[0;34mTesting shortest span:\033[0m" << std::endl;
			std::cout << sp.shortestSpan() << std::endl;
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		try
		{
			std::cout << "\033[0;34mTesting longest span:\033[0m" << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
		std::cout << "\n\033[1;35mTEST WITH 5 NUMBERS\033[0m" << std::endl;
		try
		{
			std::cout << "\033[0;35mCreating:\033[0m Span(5)" << std::endl;
			Span sp = Span(5);
			std::cout << "\033[0;35mAdding 5 random numbers:\033[0m"
				<< " Span(5) = {1 , 15, 50, 1000, 20000}" << std::endl;
			sp.addNumber(1);
			sp.addNumber(15);
			sp.addNumber(50);
			sp.addNumber(1000);
			sp.addNumber(20000);
			std::cout << "\033[0;35mLONGEST SPAN: \033[0m" << sp.longestSpan() << std::endl;
			std::cout << "\033[0;35mSHORTEST SPAN: \033[0m" << sp.shortestSpan() << std::endl;
 		}
 		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}        
	}
	{
		std::cout << "\n\033[1;32mTEST ADDING A RANGE BIGGER THAN SUPPORTS\033[0m" << std::endl;
		try
		{
			std::cout << "\033[0;32mCreating:\033[0m Span(10)" << std::endl;
			Span sp = Span(10);
			std::cout << "\033[0;32mTrying add an array of 6\033[0m: sp.addArray(11)" << std::endl;
			sp.addArray(11);
			std::cout << "\033[0;32mLONGEST SPAN: \033[0m" << sp.longestSpan() << std::endl;
			std::cout << "\033[0;32mSHORTEST SPAN: \033[0m" << sp.shortestSpan() << std::endl;
 		}
 		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}        
	}
	{
		std::cout << "\n\033[1;36mTEST WITH 100.000 NUMBERS\033[0m" << std::endl;
		Span sp = Span(100000);
		sp.addArray(100000);
		try
		{
			std::cout << "\033[0;36mLONGEST SPAN: \033[0m" << sp.longestSpan() << std::endl;
			std::cout << "\033[0;36mSHORTEST SPAN: \033[0m" << sp.shortestSpan() << std::endl;
 		}
 		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}        
	}
	return (0);
}