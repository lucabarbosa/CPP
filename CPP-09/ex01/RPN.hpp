/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 00:51:49 by lbento            #+#    #+#             */
/*   Updated: 2026/07/22 00:42:55 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include<stack>
#include <cmath>
#include <cctype>

class RPN
{
	public:
		RPN(void);
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);
		~RPN(void);
		
		int	solved(const std::string input);
};


#endif