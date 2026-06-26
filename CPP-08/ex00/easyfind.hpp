/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 16:37:17 by lbento            #+#    #+#             */
/*   Updated: 2026/06/25 22:47:54 by lbento           ###   ########.fr       */
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
		throw std::runtime_error("Value not found");
	return (result);
}

#endif