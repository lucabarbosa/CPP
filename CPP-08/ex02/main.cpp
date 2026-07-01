/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 00:51:32 by lbento            #+#    #+#             */
/*   Updated: 2026/06/30 22:28:30 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include "MutantStack.tpp"

int	main(void)
{
	{
		std::cout << "\033[1;33mTESTS FROM SUBJECT\033[0m" << std::endl;
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}
	{
		std::cout << "\n\033[1;33mSUBJECT WITH LIST\033[0m" << std::endl;
		std::list<int> mstack;
		mstack.push_back(5);
		mstack.push_back(17);
		std::cout << mstack.back() << std::endl;
		mstack.pop_back();
		std::cout << mstack.size() << std::endl;
		mstack.push_back(3);
		mstack.push_back(5);
		mstack.push_back(737);
		mstack.push_back(0);
		std::list<int>::iterator it = mstack.begin();
		std::list<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::list<int> s(mstack);
	}
	{
		std::cout << "\n\033[1;34mTESTING WITH CHAR\033[0m" << std::endl;
		MutantStack<char> mstack;
		mstack.push('L');
		mstack.push('u');
		mstack.push('c');
		mstack.push('a');
		MutantStack<char>::iterator it = mstack.begin();
		MutantStack<char>::iterator ite = mstack.end();
		std::cout << "\033[0;34mPrinting char: \033[0m";
		while (it != ite)
		{
			std::cout << *it;
			++it;
		}
		std::cout << std::endl;
		std::cout << "\033[0;34mStack top: \033[0m" << mstack.top() << std::endl;
		std::cout << "\033[0;34mStack size: \033[0m" << mstack.size() << std::endl;
		mstack.pop();
		std::cout << "\033[0;34mPoping last top char: \033[0m" << mstack.top() << std::endl;
		std::cout << "\033[0;34mStack size: \033[0m" << mstack.size() << std::endl;
	}
	{
		std::cout << "\n\033[1;36mTESTING WITH STRING\033[0m" << std::endl;
		MutantStack<std::string> mstack;
		mstack.push("Hello");
		MutantStack<std::string>::iterator it = mstack.begin();
		MutantStack<std::string>::iterator ite = mstack.end();
		std::cout << "\033[0;36mStack value: \033[0m" << *it << std::endl;
		std::cout << "\033[0;36mStack size: \033[0m" << mstack.size() << std::endl;
		std::cout << "\033[0;36mPrinting stack: \033[0m";
		while (it != ite)
		{
			std::cout << *it;
			++it;
		}
		std::cout << "\n\033[0;36m-----\033[0m" << std::endl;
		mstack.push(" World");
		std::cout << "\033[0;36mPushing\033[0m \" " << *it << "\"" << std::endl;
		MutantStack<std::string>::iterator it2 = mstack.begin();
		MutantStack<std::string>::iterator ite2 = mstack.end();
		std::cout << "\033[0;36mValue begin() after push: \033[0m" << *it2 << std::endl;
		std::cout << "\033[0;36mValue end() after push: \033[0m" << *ite2 << std::endl;
		std::cout << "\033[0;36mStack size: \033[0m" << mstack.size() << std::endl;
		std::cout << "\033[0;36mPrinting stack after push: \033[0m";
		while (it2 != ite2)
		{
			std::cout << *it2;
			++it2;
		}
		std::cout << std::endl;
	}
	return (0);
}
