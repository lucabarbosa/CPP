/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 00:54:18 by lbento            #+#    #+#             */
/*   Updated: 2026/07/22 23:41:22 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <ctime>
#include <cstdlib>
#include <cerrno>
#include <climits>
#include <cctype>

class PmergeMe
{
	private:
		std::vector<int>	_vecResult;
		std::deque<int>	_deqResult;
	public:
		PmergeMe(void);
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		~PmergeMe(void);

		void	checkNumbers(int argc, char **argv);
		int	sortVec(void);
		int	sortDeq(void);
		void	printNum();
};

#endif