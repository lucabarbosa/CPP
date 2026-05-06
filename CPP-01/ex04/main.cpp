/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 16:25:11 by lbento            #+#    #+#             */
/*   Updated: 2026/05/06 18:33:51 by lbento           ###   ########.fr       */
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
		std::cout << "Wrong number of args.\n";
		std::cout << "Format should be: ./sed <filename> <string1> <string2>\n";
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
	size_t			i;
	
	std::ifstream	infile(file.c_str());
	if (infile.fail())
		return (std::cout << "Error: Invalid \"" << file << "\" file.\n", 1);

	std::ofstream	outfile((file + ".replace").c_str());
	if (!outfile.is_open())
		return (std::cout << "Error: Can't create output file.\n", 1);
	
	while (getline(infile, line))
	{
		if (!s1.empty())
		{
			i = line.find(s1, 0);
			while (i != std::string::npos)
			{
				line.erase(i, s1.length());
				line.insert(i, s2);
				i = line.find(s1, i + s2.length());
			}
		}
		outfile << line << "\n";
	}
	infile.close();
	outfile.close();
	return (0);
}
