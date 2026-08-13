/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 00:54:18 by lbento            #+#    #+#             */
/*   Updated: 2026/08/13 18:09:39 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <utility>
#include <algorithm>
#include <ctime>
#include <iomanip>
#include <cstdlib>
#include <cerrno>
#include <climits>
#include <cctype>
#include <stdexcept>
#include <string>

class PmergeMe
{
	private:
		std::vector<int>	_vecResult;
		std::deque<int>	_deqResult;
		double					_timeVec;
		double					_timeDeq;
	public:
		PmergeMe(void);
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		~PmergeMe(void);

		void	checkNumbers(int argc, char **argv);
		void	sortVec(void);
		void	sortDeq(void);
		void	printVec(void);
		void	printDeq(void);
		void	printTime(void);
};

std::vector<int> fordJohnsonVec(std::vector<int> input);
std::deque<int> fordJohnsonDeq(std::deque<int> input);

#endif