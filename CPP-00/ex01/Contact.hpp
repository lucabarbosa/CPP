/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 22:05:59 by lbento            #+#    #+#             */
/*   Updated: 2026/04/29 14:20:45 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>

class Contact
{
	private:
		int _index;
		std::string _first_name;
		std::string _last_name;
		std::string _nickname;
		std::string _phone;
		std::string _darkest_secret;
	public:
		Contact();
		~Contact();
		Contact (int index, std::string first_name, std::string surname, std::string nickname, std::string telephone, std::string darkest_secret);
		void		set_index(int i);
		int			get_index() const;
		std::string	get_first_name() const;
		std::string	get_last_name() const;
		std::string	get_nickname() const;
		std::string	get_phone_number() const;
		std::string	get_dark_secret() const;
};

#endif