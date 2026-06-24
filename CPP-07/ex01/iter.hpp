/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 19:29:03 by lbento            #+#    #+#             */
/*   Updated: 2026/06/24 20:49:12 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template<typename T, typename F>
void  iter(T *array, const size_t size, F function)
{
   if (!array)
      return ;
   for (size_t i = 0; i < size; i++)
      function(array[i]);
}

template <typename T>
void  printValue(T const &value)
{
   std::cout << value << std::endl;
}

template <typename T>
void  addElement(T &value)
{
   value+= 1;
}

#endif