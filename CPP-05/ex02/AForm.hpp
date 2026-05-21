/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 01:39:54 by lbento            #+#    #+#             */
/*   Updated: 2026/05/21 10:47:23 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string	name;
		bool					isSigned;
		static const int	highest_grade = 1;
		static const int	lowest_grade = 150;
		const int			gradeToSign;
		const int			gradeToExec;

	public:
		AForm(void);
		AForm(const std::string &name, int gradeToSign, int gradeToExec);
		AForm(const AForm &other);
		AForm &operator=(const AForm &other);
		~AForm();

		const std::string	getName(void) const;
		bool	getIsSigned(void) const;
		int	getGradeToSign(void) const;
		int	getGradeToExec(void) const;
		void	beSigned(const Bureaucrat &bureaucrat);

		virtual void	execute(Bureaucrat const &executor) const = 0;

		class GradeTooHighException : public std::exception
		{
			public:
				const char *what() const throw();
		};
		class	GradeTooLowException : public std::exception
		{
			public:
				const char *what() const throw();
		};
		class NotSignedException : public std::exception
		{
			public:
				const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, const AForm &obj);

#endif