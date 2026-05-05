/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 16:25:11 by lbento            #+#    #+#             */
/*   Updated: 2026/05/05 16:51:28 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

int	sed_string(std::string file, std::string s1, std::string s2);

int   main(int argc, char **argv)
{
	std::string	file;
	std::string	s1;
	std::string	s2;

	if (argc != 4)
	{
		std::cout << "Wrong number of args.\nFormat should be: ./sed <filename> <string1> <string2>" << std::endl;
		return (1);
	}
	file = argv[1];
	s1 = argv[2];
	s2 = argv[3];
	if (sed_string(file, s1, s2))
		return (1);
	return (0);
}

int	sed_string(std::string file, std::string s1, std::string s2)
{
	std::string		line;
	std::ifstream	infile(file.c_str());
	std::ofstream	outfile((file + ".replace").c_str());
	size_t			i;
	
	if (!infile)
		return (std::cout << "Error: Invalid iput file.\n", 1);
	if (!outfile.is_open())
		return (std::cout << "Error: Can't create output file.\n", 1);
	
	while (getline(infile, line))
	{
		i = line.find(s1);
		while (i != std::string::npos)
		{
			if (s1.empty())
			{
				outfile << line << "\n";
				break ;
			}
			line.erase(i, s1.length());
			line.insert(i, s2);
			i = line.find(s1, i + s2.length());
		}
		if (!s1.empty())
		outfile << line << std::endl;
	}
	infile.close();
	outfile.close();
	return (0);
}
