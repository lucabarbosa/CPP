/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 12:20:02 by lbento            #+#    #+#             */
/*   Updated: 2026/05/14 15:31:59 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

class Brain
{
	private:
		std::string ideas[100];
	public:
		Brain();
		Brain(std::string idea);
		Brain(const Brain &other);
		Brain &operator=(const Brain &other);
		~Brain();

		void	setIdeas(const std::string ideas[100]);
		const std::string *getIdeas();

		void	setIdea(int i, const std::string idea);
		const std::string	getIdea(int i);
};

#endif