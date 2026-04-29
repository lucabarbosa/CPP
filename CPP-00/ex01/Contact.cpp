/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 22:05:32 by lbento            #+#    #+#             */
/*   Updated: 2026/04/29 15:03:31 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{

}

Contact::~Contact()
{
	// std::cout << "Destructor of Contact " << _index << "cleaned !" << std::endl;
}

Contact::Contact(int index, std::string firstName, std::string lastName, std::string nickname, std::string telephone, std::string darkest_secret)
{
	this->_index = index;
	this->_first_name = firstName;
	this->_last_name = lastName;
	this->_nickname = nickname;
	this->_phone = telephone;
	this->_darkest_secret = darkest_secret;
}

void		Contact::set_index(int i)
{
	_index = i;
}

int			Contact::get_index() const
{
	return (_index);
}

std::string	Contact::get_first_name() const
{
	return (_first_name);
}

std::string	Contact::get_last_name() const
{
	return (_last_name);
}
	
std::string	Contact::get_nickname() const
{
	return (_nickname);
}	

std::string	Contact::get_phone_number() const
{
	return (_phone);
}

std::string	Contact::get_dark_secret() const
{
	return (_darkest_secret);
}
	