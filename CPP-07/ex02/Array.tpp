/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 00:58:19 by lbento            #+#    #+#             */
/*   Updated: 2026/06/25 22:17:19 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
#define ARRAY_TPP

#include "Array.hpp"

template <typename T>
Array<T>::Array(void) : _value(NULL), _size(0)
{

}

template <typename T>
Array<T>::Array(unsigned int n) : _value(new T[n]()), _size(n)
{

}

template <typename T>
Array<T>::Array(const Array &other)  : _value(NULL), _size(0)
{
	*this = other;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array &other)
{
	if (this != &other)
	{
		delete[] _value;
		_size = other._size;
		_value = new T[_size];
		for (unsigned int i = 0; i < _size; i++)
			_value[i] = other._value[i];
	}
	return (*this);
}

template <typename T>
Array<T>::~Array(void)
{
	delete[] _value;
}

template <typename T>
unsigned int Array<T>::size(void) const
{
	return (_size);
}

template <typename T>
T& Array<T>::operator[](unsigned int index)
{
	if (index >= _size)
		throw std::out_of_range("\033[0;31mIndex out of range\033[0m");
	return _value[index];
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const
{
	if (index >= _size)
		throw std::out_of_range("\033[0;31mIndex out of range\033[0m");
	return _value[index];
}

template <typename T>
std::ostream&	operator<<(std::ostream &os, const Array<T> &value)
{
	for (unsigned int i = 0; i < value.size(); i++)
	{
		os << value[i];
		if (i < value.size() - 1)
			os << ", ";
	}
	return os;
}

#endif