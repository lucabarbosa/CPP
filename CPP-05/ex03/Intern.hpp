/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 13:57:04 by lbento            #+#    #+#             */
/*   Updated: 2026/05/21 14:35:24 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class AForm;

class Intern
{
	public:
		Intern();
		Intern(const Intern &other);
		Intern &operator=(const Intern &other);
		~Intern();
		
		AForm	*makeForm(std::string name, std::string target);
		AForm	*makeShrubberyCreationForm(std::string target);
		AForm	*makeRobotomyRequestForm(std::string target);
		AForm	*makePresidentialPardonForm(std::string target);
};

	#endif