/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 13:56:55 by lbento            #+#    #+#             */
/*   Updated: 2026/05/21 17:59:16 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

Intern::Intern()
{
  	std::cout << "Intern\033[0;33m has been created.\033[0m" << std::endl;
}

Intern::Intern(const Intern &other)
{
  	std::cout << "Intern\033[0;33m has been copied.\033[0m" << std::endl;
	*this = other;
}

Intern &Intern::operator=(const Intern &other)
{
  	std::cout << "Intern\033[0;33m has been assigned.\033[0m" << std::endl;
	(void)other;
	return (*this);
}

Intern::~Intern()
{
  	std::cout << "Intern\033[0;33m has been destroyed.\033[0m" << std::endl;
}
		
AForm	*Intern::makeForm(std::string form_name, std::string target)
{
	std::string forms[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
	AForm *(Intern::*ArrayForm[3])(std::string) = {
		&Intern::makeShrubberyCreationForm, &Intern::makeRobotomyRequestForm, &Intern::makePresidentialPardonForm};
	for (int i = 0; i < 3; i++)
	{
		if (form_name == forms[i])
		{
			AForm *new_form = (this->*ArrayForm[i])(target);
			std::cout << "\033[0;33mIntern creates \033[0;m" << form_name << "\033[0;33m form.\033[0;m" << std::endl;
			return (new_form);
		}
	}
	std::cout << "Intern\033[0;31m doesn’t know how to create \033[0;m" << form_name << std::endl;
	return (NULL);
}

AForm	*Intern::makeShrubberyCreationForm(std::string target)
{
	return new ShrubberyCreationForm(target);
}

AForm	*Intern::makeRobotomyRequestForm(std::string target)
{
	return new RobotomyRequestForm(target);
}

AForm	*Intern::makePresidentialPardonForm(std::string target)
{
	return new PresidentialPardonForm(target);
}
