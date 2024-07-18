/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 16:59:36 by zelabbas          #+#    #+#             */
/*   Updated: 2024/07/18 12:29:13 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string	name;
		bool				_signed;
		const int			gradeRequiredtoSign;
		const int			gradeRequiredtoExcute;

	protected:
		void checkExecution(Bureaucrat const &executor) const;

	public:
		AForm();
		AForm(const std::string&, int, int);
		AForm(const AForm&);
		virtual ~AForm();

		AForm& operator= (const AForm&);

		// getters
		const std::string&	getName(void) const;
		bool				isSigned(void) const;
		int					getGradeRequiredtoSign(void) const;
		int					getGradeRequiredtoExcute(void) const;
		
		void	beSigned(const Bureaucrat&);

		virtual void execute(Bureaucrat const & executor) const = 0;
		
		// class Exception
		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw();
		} GradeTooHighException;
		
		class GradeTooLowException : public std::exception 
		{
			public:
				const char * what() const throw();
		} GradeTooLowException;

		class	GradeNotSignedException : public std::exception
		{
			public:
				const char *what() const throw();
		} GradeNotSignedException;
};

std::ostream& operator << (std::ostream& out, const AForm& obj);
