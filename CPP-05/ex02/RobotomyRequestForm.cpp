/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 09:23:44 by lbento            #+#    #+#             */
/*   Updated: 2026/05/21 20:33:00 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm() 
	: AForm("Robotomy Request Form", 72, 45), target("Undefined target")
{

}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
	: AForm("Robotomy Request Form", 72, 45), target(target)
{

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
	: AForm(other), target(other.target)
{

}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->target = other.target;
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << this->getName() << "\033[0;33m has been destroyed.\033[0;m" << std::endl;
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (getIsSigned() == false)
		throw NotSignedException();
	else if (executor.getGrade() > getGradeToExec())
		throw GradeTooLowException();
   std::cout << "\033[0;35mBzzzt bzzzzzzt bzzzt\033[0;m" << std::endl;
   if (rand() % 2)
		std::cout << target << "\033[0;35m has been robotomized.\033[0;m 🤖" << std::endl;
	else
		std::cout << target << "\033[0;31m couldn't be robotomized.\033[0;m" << std::endl;
}
