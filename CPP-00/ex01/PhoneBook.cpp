/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 22:06:16 by lbento            #+#    #+#             */
/*   Updated: 2026/04/29 16:52:03 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

static void print_error();
static bool verify_digits(std::string str);
static void truncate_name(const std::string &str);

PhoneBook::PhoneBook()
{
	_old_contact = 0;
	_total_contacts = 0;
}

PhoneBook::~PhoneBook() {}

void PhoneBook::add_contact()
{
	std::string _first_name;
	std::string _last_name;
	std::string _nickname;
	std::string _phone;
	std::string _darkest_secret;
	
	std::cout << "\033[0;33mFirst name: \033[0m";
	std::getline(std::cin, _first_name);
	if (std::cin.eof() || _first_name.length() == 0)
		return (print_error());
		
	std::cout << "\033[0;33mLast name: \033[0m";
	std::getline(std::cin, _last_name);
	if (std::cin.eof() || _last_name.length() == 0)
		return (print_error());
	
	std::cout << "\033[0;33mNickname: \033[0m";
	std::getline(std::cin, _nickname);
	if (std::cin.eof() || _nickname.length() == 0)
		return (print_error());

	std::cout << "\033[0;33mTelephone: \033[0m";
	std::getline(std::cin, _phone);
	if (std::cin.eof() || _phone.length() == 0)
		return (print_error());
	if(!verify_digits(_phone))
	{
		std::cout << "\033[0;31mPhone non-numeric. Returning to main menu.\n\033[0m";
		std::cin.clear();
		return ;
	}
	
	std::cout << "\033[0;33mDarkest secret: \033[0m";
	std::getline(std::cin, _darkest_secret);
	if (std::cin.eof() || _darkest_secret.length() == 0)
		return (print_error());

	if (_total_contacts <= 7)
	{
		_mycontacts[_total_contacts] = Contact(_total_contacts, _first_name, _last_name,
				_nickname, _phone, _darkest_secret);
		_total_contacts++;
	}
	else
	{
		_mycontacts[_old_contact] = Contact(_old_contact, _first_name, _last_name,
				_nickname, _phone, _darkest_secret);
		_old_contact++;
		_old_contact = _old_contact % 8;
	}
}

static void print_error()
{
			std::cout << "\033[0;31mEOF detected. Returning to main menu.\n\033[0m";
			std::cin.clear();
	return ;
}

static bool verify_digits(std::string str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return (false);
	}
	return (true);
}

int PhoneBook::get_total_contacts()
{
	return (this->_total_contacts);
}

void PhoneBook::search()
{
	int	index;

	std::string ind;
	std::cout << "---------------------------------------------\n";
	std::cout << "     \033[0;34mIndex\033[0m|\033[0;34mFirst Name\033[0m|";
	std::cout << " \033[0;34mLast name\033[0m|  \033[0;34mNickname\033[0m|\n";
	for (int i = 0; i < _total_contacts; i++)
		show_contacts(i);
	std::cout << "---------------------------------------------\n";
	std::cout << "\033[0;34mInsert contact index: \033[0m";
	std::getline(std::cin, ind);
	 if (std::cin.eof())
			return (print_error());
	
	index = (ind[0] - '0') - 1;
	if (index < 0 || index >= _total_contacts || ind.length() != 1)
	{
		std::cout << "\033[0;31mIndex not valid. Returning to main menu.\033[0m" << std::endl;
		return ;
	}
	search_contact(index);
	std::cout << "---------------------------------------------\n";
}

void	PhoneBook::show_contacts(int index)
{
	std::cout << "         " << index + 1 << "|";
	truncate_name(_mycontacts[index].get_first_name());
	std::cout << "|";
	truncate_name(_mycontacts[index].get_last_name());
	std::cout << "|";
	truncate_name(_mycontacts[index].get_nickname());
	std::cout << "|";
	std::cout << std::endl;
}

static void truncate_name(const std::string &str)
{
    for (int i = 0; i < (10 - (int)str.length()) && (10 - str.length()) > 0; i++)
        std::cout << " ";    
    for (size_t i = 0; i < 9 && i < str.length(); i++)
        std::cout << str[i];
    if (str.length() == 10)
        std::cout << str[9];
    else if (str.length() > 10)
        std::cout << ".";
}

void	PhoneBook::search_contact(int index)
{

	if (index < 0 || index >= _total_contacts)
	{
		std::cout << "Index not valid !\n";
		return ;
	}
	std::cout << "\033[0;33mFirst name: \033[0m" << _mycontacts[index].get_first_name() << std::endl;
	std::cout << "\033[0;33mLast name: \033[0m" << _mycontacts[index].get_last_name() << std::endl;
	std::cout << "\033[0;33mNickname: \033[0m" << _mycontacts[index].get_nickname() << std::endl;
	std::cout << "\033[0;33mPhone number: \033[0m" << _mycontacts[index].get_phone_number() << std::endl;
	std::cout << "\033[0;33mDarkest secret: \033[0m" << _mycontacts[index].get_dark_secret() << std::endl;
}
