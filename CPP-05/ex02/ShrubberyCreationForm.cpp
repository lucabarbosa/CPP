/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 21:24:56 by lbento            #+#    #+#             */
/*   Updated: 2026/05/21 19:01:35 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() 
	: AForm("Shrubbery Creation Form", 145, 137), target("Undefined target")
{
	std::cout << this->getName() <<"\033[0;33m constructor has been created.\033[0;m" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: AForm("Shrubbery Creation Form", 145, 137), target(target)
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
	: AForm(other), target(other.target)
{
	std::cout << "\033[0;33mShruberry constructor has been copied.\033[0;m" << std::endl;
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
	std::cout << this->getName() << "\033[0;33m has been destroyed.\033[0;m" << std::endl;
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	std::string	filename = target + "_shrubbery";

	if (getIsSigned() == false)
		throw NotSignedException();
	else if (executor.getGrade() > getGradeToExec())
		throw GradeTooLowException();
	std::ofstream	outfile(filename.c_str());
	if (outfile.is_open())
	{
		for (int i = 0; i < 3; i++)
		{
			outfile << "   /\\      /\\ \n";
			outfile << "  /**\\    /**\\ \n";
			outfile << " /****\\  /****\\ \n";
			outfile << "   ||      || \n\n";
		}
		std::cout << "\033[1;35m" << filename << "\033[0;33m created !\033[0;m" << std::endl;
		outfile.close();
		return ;
	}
	std::cout << "\033[1;31mFailed to create file \033[0m" << filename << std::endl;
	return ;
}
