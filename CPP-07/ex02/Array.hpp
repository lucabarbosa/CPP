/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 17:43:46 by lbento            #+#    #+#             */
/*   Updated: 2026/06/25 01:17:17 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>

template<typename T>
class Array
{
	private:
		T	*_value;
		unsigned int	_size;
	public:
		Array(void);
		Array(unsigned int n);
		Array(const Array &other);
		Array &operator=(const Array &other);
		~Array(void);

		unsigned int size(void) const;
		T &operator[](unsigned int index);
		const T &operator[](unsigned int index) const;
};

template<typename T>
std::ostream &operator<<(std::ostream &out, const Array<T> &value);


#endif