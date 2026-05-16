/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 10:40:25 by lbento            #+#    #+#             */
/*   Updated: 2026/05/16 12:14:53 by lbento           ###   ########.fr       */
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
	std::cout << name << "\033[0;33m with grade" << grade << " has been created.\033[0m" << std::endl;
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

const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is Too High! 👍");
}

const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is Too Low! 👎");
}

std::ostream &operator<<(std::ostream &out, Bureaucrat &obj)
{
	out << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".";
	return out;
}