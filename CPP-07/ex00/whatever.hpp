/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 19:28:16 by lbento            #+#    #+#             */
/*   Updated: 2026/06/23 23:16:24 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template<typename T>
void swap(T &a, T &b)
{
	T temp;

	temp = a;
	a = b;
	b = temp;
}

template<typename T>
const T &min(const T &a, const T &b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

template<typename T>
const T &max(const T &a, const T &b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

#endif