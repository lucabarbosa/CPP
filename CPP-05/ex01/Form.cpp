/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 01:41:34 by lbento            #+#    #+#             */
/*   Updated: 2026/05/21 10:19:41 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"


Form::Form(void) : name("Default"), gradeToSign(42), gradeToExec(42)
{
	this->isSigned = false;
	std::cout << name << "\033[0;33m has been created.\033[0m" << std::endl;
}

Form::Form(const std::string &name, int gradeToSign, int gradeToExec)
	: name(name), gradeToSign(gradeToSign), gradeToExec(gradeToExec)
{
	this->isSigned = false;
	if (gradeToSign < highest_grade || gradeToExec < highest_grade)
		throw	Form::GradeTooHighException();
	else if (gradeToSign > lowest_grade || gradeToExec > lowest_grade)
		throw	Form::GradeTooLowException();
	std::cout << name << "\033[0;33m has been created.\033[0m" << std::endl;
}

Form::Form(const Form &other)
	: name(other.name), gradeToSign(other.gradeToSign), gradeToExec(other.gradeToExec)
{
	if (gradeToSign < highest_grade || gradeToExec < highest_grade)
		throw	Form::GradeTooHighException();
	else if (gradeToSign > lowest_grade || gradeToExec > lowest_grade)
		throw	Form::GradeTooLowException();
	*this = other;
	std::cout << other.getName() << "\033[0;33m has been copied.\033[0m" << std::endl;
}

Form &Form::operator=(const Form &other)
{
	std::cout << other.getName() << "\033[0;33m has been assigned from another form.\033[0m" << std::endl;
	return (*this);
}

Form::~Form(void)
{
	std::cout << "Form\033[0;33m has been destroyed.\033[0m" << std::endl;
}

const std::string Form::getName(void) const
{
	return (this->name);	
}

bool	Form::getIsSigned(void) const
{
	return (this->isSigned);
}

int	Form::getGradeToSign(void) const
{
	return (this->gradeToSign);
}

int	Form::getGradeToExec(void) const
{
	return (this->gradeToExec);
}

void	Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (gradeToSign < bureaucrat.getGrade())
		throw GradeTooLowException();
	this->isSigned = true;
}


const char	*Form::GradeTooHighException::what() const throw()
{
	return ("\033[1;31mGrade is Too High! ⬆\033[0m");
}

const char	*Form::GradeTooLowException::what() const throw()
{
	return ("\033[1;31mGrade is Too Low! ⬇\033[0m");
}

const char	*Form::NotSignedException::what() const throw()
{
	return ("\033[1;31mForm is not signed!\033[0m");
}

std::ostream &operator<<(std::ostream &out, const Form &obj)
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