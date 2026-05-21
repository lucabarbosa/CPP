/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 21:26:53 by lbento            #+#    #+#             */
/*   Updated: 2026/05/21 20:33:24 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm() 
	: AForm("Presidential Pardon Form", 25, 5), target("Undefined target")
{

}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
	: AForm("Presidential Pardon Form", 25, 5), target(target)
{

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
	: AForm(other), target(other.target)
{

}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->target = other.target;
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << this->getName() << "\033[0;33m has been destroyed.\033[0;m" << std::endl;
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (getIsSigned() == false)
		throw NotSignedException();
	else if (executor.getGrade() > getGradeToExec())
		throw GradeTooLowException();
	std::cout << target << "\033[0;36m has been pardoned by Zaphod Beeblebrox.\033[0;m" << std::endl;
}
