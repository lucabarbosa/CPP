/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 16:37:17 by lbento            #+#    #+#             */
/*   Updated: 2026/06/28 10:05:55 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

template<typename T>
typename T::iterator easyfind(T &container, const int value)
{
	typename T::iterator	result = std::find(container.begin(), container.end(), value);
	if (result == container.end())
		throw std::runtime_error("\033[0;31mValue not found\033[0m");
	return (result);
}

#endif