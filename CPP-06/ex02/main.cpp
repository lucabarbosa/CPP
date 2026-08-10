/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 23:36:02 by lbento            #+#    #+#             */
/*   Updated: 2026/08/10 15:29:36 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void);
void identify(Base* p);
void identify(Base& p);

int   main(void)
{
	std::srand(static_cast<unsigned int>(std::time(NULL)));
	{
		std::cout << "\033[3;33m Creating and identifying classes by pointers\033[0m" << std::endl;
		Base *a = new A();
		Base *b = new B();
		Base *c = new C();
		identify(a);
		identify(b);
		identify(c);
		std::cout << "\n";

		std::cout << "\033[3;33m Identifying classes by references\033[0m" << std::endl;
		identify(*a);
		identify(*b);
		identify(*c);
		delete a;
		delete b;
		delete c;
	}
	{
		std::cout << "\n\033[3;33m Creating and identifying random classes\033[0m" << std::endl;
		Base*	base;
		for (int i = 0; i < 10; i++)
		{
			base = generate();
			identify(base);
			identify(*base);
			delete(base);
			std::cout << std::endl;
		}
	}
	return (0);
}

Base * generate(void)
{
	int random = std::rand() % 3;
	 
	if (random == 0)
	{
		std::cout << "\033[1;32mCreated and returned A class\033[0m" << std::endl;
		return new A;
	}
	else if (random == 1)
	{
		std::cout << "\033[1;36mCreated and returned B class\033[0m" << std::endl;
		return new B;
	}
	else
	{
		std::cout << "\033[1;35mCreated and returned C class\033[0m" << std::endl;
		return new C;
	}   
}

void	identify(Base* p)
{
	Base *temp = dynamic_cast<A*>(p);
	if (temp != NULL)
	{
		std::cout << "\033[0;32mPointed class is A!\033[0m" << std::endl;
		return ;
	}
	temp = dynamic_cast<B*>(p);
	if (temp != NULL)
	{
		std::cout << "\033[0;36mPointed class is B!\033[0m" << std::endl;
		return ;
	}
	temp = dynamic_cast<B*>(p);
	if (temp != NULL)
	{
		std::cout << "\033[0;35mPointed class is C!\033[0m" << std::endl;
		return ;
	}
	else
		std::cout << "\033[0;31mPointed class is unknown type!\033[0m" << std::endl;
}

void identify(Base &p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "Type is A!\n";
		return ;
	}
	catch(const std::exception& e){}

	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "\033[0;36mReferenced class is B!\033[0m" << std::endl;
		return ;
	}
	catch(const std::exception& e){}

	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "\033[0;35mReferenced class is C!\033[0m" << std::endl;
		return ;
	}
	catch(const std::exception& e){}
}
