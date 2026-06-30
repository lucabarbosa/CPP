/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 21:57:41 by lbento            #+#    #+#             */
/*   Updated: 2026/06/30 01:10:16 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <list>
#include <stack>

template<typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack(void);
		MutantStack(const MutantStack &other);
		MutantStack &operator=(const MutantStack &other);
		~MutantStack(void);
	
		typedef typename std::stack(T)::container_type::iterator iterator;
		typedef typename std::stack(T)::container_type::const_iterator const_iterator;

		iterator begin(void);
		iterator end(void);
		const_iterator begin(void);
		const_iterator end(void);
		
};

#include "MutantStack.tpp"

#endif