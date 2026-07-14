/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 00:50:28 by lbento            #+#    #+#             */
/*   Updated: 2026/07/13 23:31:40 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void)
{

}

BitcoinExchange::BitcoinExchange(const BitcoinExchange  &other) : _data(other._data)
{

}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange  &other)
{
	if (this != &other)
	{
		_data = other._data;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange(void)
{

}


static bool	splitLine(const std::string &line, const std::string &delim,
		std::string &left, std::string &right);
static	std::string trimLine(const std::string &s);

void	BitcoinExchange::loadInput(const std::string file_name)
{
	std::ifstream	file(file_name.c_str());
	checkFile(file, file_name, "date,exchange_rate");

	std::string line;
	while (std::getline(file, line))
	{
		if (line.empty())
			continue;
		std::string dateStr, rateStr;
		if (!splitLine(line, ",", dateStr, rateStr))
			continue;
		dateStr = trimLine(dateStr);
		rateStr = trimLine(rateStr);
		if (!checkDate(dateStr))
			continue;
		double rate = std::atof(rateStr.c_str());
		_data[dateStr] = rate;
	}
}

void	BitcoinExchange::processInput(std::string file_name)
{
	std::ifstream	file(file_name.c_str());
	checkFile(file, file_name, "date | value");

	std::string line;
	while (std::getline(file, line))
	{
		if (line.empty())
			continue;
		double value;
		std::string dateStr, valueStr;
		char *endptr;
		if (!splitLine(line, "|", dateStr, valueStr))
		{
			std::cerr << "\033[1;31mError:\033[0m bad input \033[1;31m=>\033[0m " << line << std::endl;
			continue;
		}
		dateStr  = trimLine(dateStr);
		valueStr = trimLine(valueStr);
		if (!checkDate(dateStr))
		{
			std::cerr << "\033[1;31mError:\033[0m bad input \033[1;31m=>\033[0m " << dateStr << std::endl;
			continue;
		}
		value = std::strtod(valueStr.c_str(), &endptr);
		if (valueStr.empty() || *endptr != '\0')
		{
			std::cerr << "\033[1;31mError:\033[0m bad input \033[1;31m=>\033[0m " << line << std::endl;
			continue;
		}
		if (value < 0)
		{
			std::cerr << "\033[1;31mError:\033[0m not a positive number." << std::endl;
			continue;
		}
		if (value > 1000)
		{
			std::cerr << "\033[1;31mError:\033[0m too large a number." << std::endl;
			continue;
		}
		std::map<std::string, double>::iterator it = _data.upper_bound(dateStr);
		if (it == _data.begin())
		{
			std::cerr << "\033[1;31mError:\033[0m no earlier rate available for => " << dateStr << std::endl;
			continue;
		}
		--it;
		std::cout << dateStr << " => " << valueStr << " = " << (it->second * value) << std::endl;
	}
}

bool	checkDate(const std::string date)
{
	int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if (date.length() != 10)
		return false;
	if (date[4] != '-' || date[7] != '-')
		return false;
	for (int i = 0; i < 10; i++)
	{
		if (i == 4 || i == 7)
			continue;
		if (!std::isdigit(static_cast<unsigned char>(date[i])))
			return false;
	}

	int year  = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day   = std::atoi(date.substr(8, 2).c_str());
	if (month < 1 || month > 12)
		return false;
	int maxDay = daysInMonth[month - 1];
	if (month == 2 && ((year % 400 == 0) ||
		 (year % 4 == 0 && year % 100 != 0)))
		maxDay = 29;
	if (day < 1 || day > maxDay)
		return false;
	return true;
}

void	checkFile(std::ifstream &file, const std::string &name, std::string expect_line)
{
	if (!file.is_open())
		throw std::runtime_error("\033[0;31mCan't open the file: \033[0m" + name);

	std::string line;
	std::getline(file, line);
	if (line != expect_line)
		throw std::runtime_error("\033[0;31mInvalid expected file header: \033[0m" + name);
}

static bool splitLine(const std::string &line, const std::string &delim,
					   std::string &left, std::string &right)
{
	size_t pos = line.find(delim);
	if (pos == std::string::npos)
		return false;
	left  = line.substr(0, pos);
	right = line.substr(pos + delim.length());
	return true;
}

static std::string trimLine(const std::string &s)
{
	size_t start = s.find_first_not_of(" \t");
	size_t end   = s.find_last_not_of(" \t");
	if (start == std::string::npos)
		return "";
	return s.substr(start, end - start + 1);
}
