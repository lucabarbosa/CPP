/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 01:39:54 by lbento            #+#    #+#             */
/*   Updated: 2026/05/18 02:13:30 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string	name;
		static const int	highest_grade = 1;
		static const int	lowest_grade = 150;
		const int			gradeToSign;
		const int			gradeToExec;
		bool					isSigned;
	public:
		Form(void);
		Form(const std::string &name, int gradeToSign, int gradeToExec);
		Form(const Form &other);
		Form &operator=(const Form &other);
		~Form();

		const std::string	getName(void) const;
		bool	getIsSigned(void) const;
		int	getGradeToSign(void) const;
		int	getGradeToExec(void) const;
		void	beSigned(const Bureaucrat &bureaucrat);

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
		class AlreadySignedException : public std::exception
		{
			public:
				const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, const Form &obj);

#endif