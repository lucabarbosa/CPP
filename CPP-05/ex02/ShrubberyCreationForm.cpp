/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 21:24:56 by lbento            #+#    #+#             */
/*   Updated: 2026/05/21 10:27:56 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() 
	: AForm("Shrubbery Creation Form", 145, 137), target("Undefined target")
{
	std::cout << "Shruberry constructor has been created." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: AForm("Shrubbery Creation Form", 145, 137), target(target)
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
	: AForm(other), target(other.target)
{
	std::cout << "Shruberry constructor has been copied." << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->target = other.target;
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "Shruberry constructor has been destroyed." << std::endl;
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	std::string	filename = target + "_shrubbery";
	std::ofstream	outfile(filename.c_str());

	if (getIsSigned() == false)
		throw NotSignedException();
	else if (executor.getGrade() > getGradeToExec())
		throw GradeTooLowException();
	if (outfile.is_open())
	{
		outfile << "   /\ ";
		outfile << " /**\ ";
		outfile << "   || ";
		outfile.close();
		return ;
	}
	std::cout << "\033[1;31mFailed to create file \033[0m" << filename << std::endl;
	return ;
}
