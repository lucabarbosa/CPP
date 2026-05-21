/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 10:40:25 by lbento            #+#    #+#             */
/*   Updated: 2026/05/21 11:45:55 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : name(""), grade(150)
{
	std::cout << "Bureaucrat\033[0;33m has been created.\033[0m" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name)
{
	if (grade < highest_grade)
		throw	Bureaucrat::GradeTooHighException();
	else if (grade > lowest_grade)
		throw	Bureaucrat::GradeTooLowException();
	this->grade = grade;
	std::cout << name << "\033[0;33m with grade \033[0m" << grade << "\033[0;33m has been created.\033[0m" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.getName()), grade(other.getGrade())
{
	std::cout << "Bureaucrat\033[0;33m has been copied.\033[0m" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	std::cout << "Bureaucrat\033[0;33m has been assigned from another bureaucrat.\033[0m" << std::endl;
	if (this != &other)
		grade = other.getGrade();
	return (*this);	
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Bureaucrat\033[0;33m has been destroyed.\033[0m" << std::endl;
}

const std::string Bureaucrat::getName(void) const
{
	return (this->name);	
}

int	Bureaucrat::getGrade() const
{
	return (this->grade);
}

void	Bureaucrat::incrementGrade(void)
{
	if (this->grade <= highest_grade)
		throw Bureaucrat::GradeTooHighException();
	this->grade--;
}

void	Bureaucrat::decrementGrade(void)
{
	if (this->grade >= lowest_grade)
		throw Bureaucrat::GradeTooLowException();
	this->grade++;
}

void	Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << name << "\033[0;34m signed \033[0m" << form.getName() << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cout << name << "\033[0;31m can't sign \033[0m" << form.getName()
			<< "\033[0;31m because the \033[0m" << e.what() << std::endl;
	}	
}

void Bureaucrat::executeForm(const AForm &form) const
{
	try
	{
		form.execute(*this);
		std::cout << this->getName() << "\033[0;33m executed \033[0;m" << form.getName() << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cout << this->getName() << "\033[0;31m can't execute \033[0;m" << form.getName()
			<< "\033[0;31m because \033[0;m" << e.what() << std::endl;
	}
	
}

const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("\033[1;31mGrade is Too High! ⬆\033[0m");
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("\033[1;31mGrade is Too Low! ⬇\033[0m");
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &obj)
{
	out << obj.getName() << "\033[0;33m, bureaucrat grade \033[0m" << obj.getGrade() << "\033[0;33m.\033[0m";
	return out;
}