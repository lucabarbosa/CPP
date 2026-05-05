/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 09:40:36 by lbento            #+#    #+#             */
/*   Updated: 2026/05/04 22:47:06 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
   private:
		std::string name;

	public:
		Zombie(std::string name);
		Zombie();
		~Zombie();
		void  announce(void);
		void	set_name(std::string name);
		std::string	get_name(void);
};

#endif