/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 21:58:01 by lbento            #+#    #+#             */
/*   Updated: 2026/06/30 01:08:44 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_TPP
#define MUTANTSTACK_TPP

template<typename T>
MutantStack<T>::MutantStack(void)
{
	
}

template<typename T>
MutantStack<T>::MutantStack(const MutantStack &other) : std::stack<T>(other)
{

}

template<typename T>
MutantStack<T>&MutantStack<T>::operator=(const MutantStack &other)
{
	if (this != &other)
	{
		std::stack<T>::operator=(other);
	}
	return (*this);
}

template<typename T>
MutantStack<T>::~MutantStack(void)
{

}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin(void)
{
	return (this->c.begin());
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::end(void)
{
	return (this->c.end());
}

template<typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::cbegin(void)
{
	return (this->c.cbegin());
}

template<typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::cend(void)
{
	return (this->c.cend());
}

#endif