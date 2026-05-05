/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 09:40:09 by lbento            #+#    #+#             */
/*   Updated: 2026/05/05 00:41:22 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int   main(void)
{
	std::string	brain = "HI THIS IS BRAIN";
	std::string	*stringPTR = &brain;
	std::string	&stringREF = brain;

	std::cout << "\033[0;34mThe address of the string:\033[0m " << &brain << std::endl;
	std::cout << "\033[0;34mThe stringPTR memory address:\033[0m " << stringPTR << std::endl;
	std::cout << "\033[0;34mThe stringREF memory address:\033[0m " << &stringREF << std::endl;
	
	std::cout << "\n\033[0;32mThe value of the string:\033[0m " << brain << std::endl;
	std::cout << "\033[0;32mThe value pointed to by stringPTR:\033[0m " << *stringPTR << std::endl;
	std::cout << "\033[0;32mThe value pointed to by stringREF:\033[0m " << stringREF << std::endl;
	return (0);
}
