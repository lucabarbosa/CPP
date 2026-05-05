/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 00:45:06 by lbento            #+#    #+#             */
/*   Updated: 2026/05/05 12:51:14 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <string.h>

class Weapon
{
	private:
		std::string type;
	public:
		Weapon(std:: string type);
		~Weapon();
		std::string	getType(void);
		void	setType(std::string type);
};

#endif