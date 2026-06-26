/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 17:44:05 by lbento            #+#    #+#             */
/*   Updated: 2026/06/25 22:16:36 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

#define MAX_VAL 750

int   main(int, char **)
{
	{
		std::cout << "\033[3;33mSubject Tests\033[0m" << std::endl;
		Array<int>	numbers(MAX_VAL);
		int*	mirror = new int[MAX_VAL];
		srand(time(NULL));
		for (int i = 0; i < MAX_VAL; i++)
		{
			const int	value = rand();
			numbers[i] = value;
			mirror[i] = value;
		}
		//SCOPE
		{
			Array<int> tmp = numbers;
			Array<int> test(tmp);
		}
		for (int i = 0; i < MAX_VAL; i++)
		{
			if(mirror[i] != numbers[i])
			{
				std::cerr << "didn't save the same value!!" << std::endl;
				return 1;
			}
		}
		try
		{
			numbers[-2] = 0;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			numbers[MAX_VAL] = 0;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		for (int i = 0; i < MAX_VAL; i++)
		{
			numbers[i] = rand();
		}
		delete [] mirror;
	}
	{
		std::cout << "\n\033[1;34mCopy constructor\033[0m" << std::endl;
		Array<int>	a(5);
		Array<int>	b(a);
		std::cout << "\033[0;34mValue of b= \033[0m" << b << "\033[0;34m and size= \033[0m" << b.size() << std::endl;
		std::cout << "\033[1;34mVerifying deep copy\033[0m" << std::endl;
		for (unsigned int i = 0; i < a.size(); i++)
			a[i] = (i + 1) * 10;
		for (unsigned int i = 0; i < b.size(); i++)
			b[i] = (i + 1) * 5;
		std::cout << "\033[0;34mValue of a= \033[0m" << a << "\033[0;34m and size= \033[0m" << a.size() << std::endl;
		std::cout << "\033[0;34mValue of b= \033[0m" << b << "\033[0;34m and size= \033[0m" << b.size() << std::endl;
	}
	{
		std::cout << "\n\033[1;35mAssigment operator\033[0m" << std::endl;
		Array<int>	a(5);
		Array<int>	b;
		for (unsigned int i = 0; i < a.size(); i++)
			a[i] = (i + 1) * 10;
		b = a;
		std::cout << "\033[0;35mValue of b= \033[0m" << b << "\033[0;35m and size= \033[0m" << b.size() << std::endl;
		std::cout << "\033[1;35mVerifying deep copy\033[0m" << std::endl;
		for (unsigned int i = 0; i < b.size(); i++)
			b[i] = i * 100;
		std::cout << "\033[0;35mValue of a= \033[0m" << a << "\033[0;35m and size= \033[0m" << a.size() << std::endl;
		std::cout << "\033[0;35mValue of b= \033[0m" << b << "\033[0;35m and size= \033[0m" << b.size() << std::endl;
	}
	{
		std::cout << "\n\033[1;36mStrings\033[0m" << std::endl;
		Array<std::string> a(6);
		a[0] = "One";
		a[1] = "Two";
		a[2] = "Three";
		a[3] = "Four";
		a[4] = "Five";
		a[5] = "Guys";
		std::cout << "\033[0;36mValue of a= \033[0m" << a << "\033[0;36m and size= \033[0m" << a.size() << std::endl;
		try
		{
			std::cout << "\033[1;36mVerifying acess operator\033[0m" << std::endl;
			std::cout << "\033[0;36ma[0] = \033[0m" << a[0] << std::endl;
			std::cout << "\033[0;36ma[4] = \033[0m" << a[4] << std::endl;
			std::cout << "\033[0;36ma[5] = \033[0m" << a[5] << std::endl;
			std::cout << "\033[0;36mTesting out of range a[6] = \033[0m" << a[6] << std::endl;
		}
		catch(const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		
	}
	return (0);
}
