/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 19:03:40 by lbento            #+#    #+#             */
/*   Updated: 2026/05/05 19:12:18 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <string>
#include <iostream>

class Harl
{
	private:
        void	debug(void);
        void	info(void);
        void	warning(void);
        void	error(void);
	public:
		Harl();
		~Harl();
		void	complain(std::string level);
};

#endif