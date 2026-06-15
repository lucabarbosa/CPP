/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 22:28:27 by lbento            #+#    #+#             */
/*   Updated: 2026/06/14 23:32:24 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int   main(void)
{
	Data data;
	data.str = "Hello World";
	data.num = 42;
	uintptr_t	int_pointer;

	std::cout << "\033[1;35m----- Data Struct Values -----\033[0m" << std::endl;
	std::cout << "\033[0;35mString pointer: \033[0m" << data.str << std::endl;
	std::cout << "\033[0;35mNumber pointer: \033[0m" << data.num << std::endl;
	std::cout << "\033[0;35mOriginal pointer: \033[0m" << &data << std::endl;
	
	std::cout << "\n\033[1;33m----- Serialize Data -----\033[0m" << std::endl;
	int_pointer = Serializer::serialize(&data);
	std::cout << "\033[0;33mInt pointer:\033[0m 0x" << std::hex << int_pointer << std::dec << std::endl;

	std::cout << "\n\033[1;34m----- Deserialize Data -----\033[0m" << std::endl;
	Data	*back;
	back = Serializer::deserialize(int_pointer);
	std::cout << "\033[0;34mString: \033[0m" << back->str << std::endl;
	std::cout << "\033[0;34mNumber: \033[0m" << back->num << std::endl;
	std::cout << "\033[0;34mDeserialized pointer: \033[0m" << back << std::endl;

	if (back == &data)
		std::cout << "\n\033[1;32mPointer deserialized matches with original pointer\033[0m" << std::endl;
	else
		std::cout << "\n\033[1;31mPointer deserialized DON'T matches with original pointer\033[0m" << std::endl;
	return (0);
}
