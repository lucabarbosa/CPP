/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 01:41:34 by lbento            #+#    #+#             */
/*   Updated: 2026/05/21 10:20:40 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"


AForm::AForm(void) : name("Default"), gradeToSign(42), gradeToExec(42)
{
	this->isSigned = false;
	std::cout << name << "\033[0;33m has been created.\033[0m" << std::endl;
}

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExec)
	: name(name), gradeToSign(gradeToSign), gradeToExec(gradeToExec)
{
	this->isSigned = false;
	if (gradeToSign < highest_grade || gradeToExec < highest_grade)
		throw	AForm::GradeTooHighException();
	else if (gradeToSign > lowest_grade || gradeToExec > lowest_grade)
		throw	AForm::GradeTooLowException();
	std::cout << name << "\033[0;33m has been created.\033[0m" << std::endl;
}

AForm::AForm(const AForm &other)
	: name(other.name), gradeToSign(other.gradeToSign), gradeToExec(other.gradeToExec)
{
	if (gradeToSign < highest_grade || gradeToExec < highest_grade)
		throw	AForm::GradeTooHighException();
	else if (gradeToSign > lowest_grade || gradeToExec > lowest_grade)
		throw	AForm::GradeTooLowException();
	*this = other;
	std::cout << other.getName() << "\033[0;33m has been copied.\033[0m" << std::endl;
}

AForm &AForm::operator=(const AForm &other)
{
	std::cout << other.getName() << "\033[0;33m has been assigned from another form.\033[0m" << std::endl;
	return (*this);
}

AForm::~AForm(void)
{
	std::cout << "AForm\033[0;33m has been destroyed.\033[0m" << std::endl;
}

const std::string AForm::getName(void) const
{
	return (this->name);	
}

bool	AForm::getIsSigned(void) const
{
	return (this->isSigned);
}

int	AForm::getGradeToSign(void) const
{
	return (this->gradeToSign);
}

int	AForm::getGradeToExec(void) const
{
	return (this->gradeToExec);
}

void	AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (gradeToSign < bureaucrat.getGrade())
		throw GradeTooLowException();
	this->isSigned = true;
}


const char	*AForm::GradeTooHighException::what() const throw()
{
	return ("\033[1;31mGrade is Too High! ⬆\033[0m");
}

const char	*AForm::GradeTooLowException::what() const throw()
{
	return ("\033[1;31mGrade is Too Low! ⬇\033[0m");
}

const char	*AForm::NotSignedException::what() const throw()
{
	return ("\033[1;31mForm is not signed!\033[0m");
}

std::ostream &operator<<(std::ostream &out, const AForm &obj)
{
	out << obj.getName() << "\033[0;33m form is \033[0m";
	if (obj.getIsSigned())
		out << "signed";
	else
		out << "unsigned";
	out << "\033[0;33m. Grade to sign: \033[0m" << obj.getGradeToSign()
		<< "\033[0;33m. Grade to execute: \033[0m"<< obj.getGradeToExec() << "\033[0;33m.\033[0m";
	return out;
}