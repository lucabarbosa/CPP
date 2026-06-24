/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 19:27:17 by lbento            #+#    #+#             */
/*   Updated: 2026/06/24 00:45:05 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int   main(void)
{
	{
		std::cout << "\033[3;33m Tests from subjects \033[0m" << std::endl;
		int a = 2;
		int b = 3;
		
		::swap( a, b );
		std::cout << "\033[0;33ma = " << a << ", b = " << b << std::endl;
		std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
		std::cout << "max(a, b) = " << ::max(a, b) << std::endl;
		
		std::string c = "chaine1";
		std::string d = "chaine2";
		
		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
		std::cout << "max(c, d) = " << ::max(c, d) << std::endl;
		std::cout << "\033[0m" << std::endl;
	}
	{
		std::cout << "\033[1;35m Testing with ints\033[0m" << std::endl;
		int a = 4;
		int b = 2;
		
		std::cout << "\033[0;35mNumbers \033[0ma= " << a << " b= " << b << std::endl;
		::swap(a, b);
		std::cout << "\033[0;35mNumbers after swaps \033[0ma= " << a << " b= " << b << std::endl;
		std::cout << "\033[0;35mMin num (a, b) \033[0ma= " << ::min(a, b) << std::endl;
		std::cout << "\033[0;35mMax num (a, b) \033[0ma= " << ::max(a, b) << std::endl;
		std::cout << "\033[0m" << std::endl;
	}
	{
		std::cout << "\033[1;36m Testing with doubles\033[0m" << std::endl;
		double a = 42.42;
		double b = 21.21;
		
		std::cout << "\033[0;36mNumbers \033[0ma= " << a << " b= " << b << std::endl;
		::swap(a, b);
		std::cout << "\033[0;36mNumbers after swaps \033[0ma= " << a << " b= " << b << std::endl;
		std::cout << "\033[0;36mMin num (a, b) \033[0ma= " << ::min(a, b) << std::endl;
		std::cout << "\033[0;36mMax num (a, b) \033[0ma= " << ::max(a, b) << std::endl;
		std::cout << "\033[0m" << std::endl;
	}
	{
		std::cout << "\033[1;34m Testing with chars\033[0m" << std::endl;
		char a = 'a';
		char b = 'b';
		
		std::cout << "\033[0;34mNumbers \033[0ma= " << a << " b= " << b << std::endl;
		::swap(a, b);
		std::cout << "\033[0;34mNumbers after swaps \033[0ma= " << a << " b= " << b << std::endl;
		std::cout << "\033[0;34mMin num (a, b) \033[0ma= " << ::min(a, b) << std::endl;
		std::cout << "\033[0;34mMax num (a, b) \033[0ma= " << ::max(a, b) << std::endl;
		std::cout << "\033[0m" << std::endl;
	}
	{
		std::cout << "\033[1;32m Testing with strings\033[0m" << std::endl;
		std::string a = "Forty";
		std::string b = "Two";
		
		std::cout << "\033[0;32mNumbers \033[0ma= " << a << " b= " << b << std::endl;
		::swap(a, b);
		std::cout << "\033[0;32mNumbers after swaps \033[0ma= " << a << " b= " << b << std::endl;
		std::cout << "\033[0;32mMin num (a, b) \033[0ma= " << ::min(a, b) << std::endl;
		std::cout << "\033[0;32mMax num (a, b) \033[0ma= " << ::max(a, b) << std::endl;
		std::cout << "\033[0m" << std::endl;
	}
	return (0);
}
