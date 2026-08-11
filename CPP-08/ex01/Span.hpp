/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 09:37:07 by lbento            #+#    #+#             */
/*   Updated: 2026/08/11 18:49:47 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <vector>

class Span
{
	private:
		Span(void);
		unsigned int	_maxSize;
		std::vector<int> _numbers;
	public:
		Span(unsigned int N);
		Span(const Span &other);
		Span &operator=(const Span &other);
		~Span(void);
		
		void	addNumber(int number);
		int	shortestSpan(void);
		int	longestSpan(void);
		void	addArray(unsigned int size);
		
		template <typename Iterator>
		void	checkRange(Iterator first, Iterator last)
		{
			if (std::distance(first, last) + _numbers.size() > _maxSize)
				throw	std::length_error("\033[0;31mNot enough numbers to calculate.\033[0m");
			_numbers.insert(_numbers.end(), first, last);
		}
};


#endif