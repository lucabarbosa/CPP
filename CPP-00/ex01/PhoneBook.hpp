/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 22:06:34 by lbento            #+#    #+#             */
/*   Updated: 2026/05/06 18:06:58 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  PHONEBOOK_HPP
#define  PHONEBOOK_HPP

#include <cstdlib>
#include "Contact.hpp"

class PhoneBook
{
    private:
        int _old_contact;
        int _total_contacts;
        Contact _mycontacts[8];
    public:
        PhoneBook();
        ~PhoneBook();
        void add_contact();
        void show_contacts(int index);
        void search();
        void search_contact(int index);
        int get_total_contacts();
};

#endif