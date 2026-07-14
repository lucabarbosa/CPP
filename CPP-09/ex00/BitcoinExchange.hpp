/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 00:49:49 by lbento            #+#    #+#             */
/*   Updated: 2026/07/13 23:00:24 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP


#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>
#include <string>
#include <ctime>
#include <map>

class BitcoinExchange
{
	private:
		std::map<std::string, double>	_data;
	public:
		BitcoinExchange(void);
		BitcoinExchange(const BitcoinExchange  &other);
		BitcoinExchange &operator=(const BitcoinExchange  &other);
		~BitcoinExchange(void);

		void	loadInput(const std::string file_name);
		void	processInput(const std::string file_name);
};

bool	checkDate(const std::string date);
void	checkFile(std::ifstream &file, const std::string &name, std::string expect_line);

#endif