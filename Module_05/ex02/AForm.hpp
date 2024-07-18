/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 16:59:36 by zelabbas          #+#    #+#             */
/*   Updated: 2024/07/18 09:30:43 by zelabbas         ###   ########.fr       */
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
		
	public:
		AForm();
		AForm(const std::string&, int, int);
		AForm(const AForm&);
		~AForm();

		AForm& operator= (const AForm&);

		// getters
		const std::string&	getName(void) const;
		bool				isSigned(void) const;
		int					getGradeRequiredtoSign(void) const;
		int					getGradeRequiredtoExcute(void) const;
		
		void	beSigned(const Bureaucrat&);
		
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
};

std::ostream& operator << (std::ostream& out, const AForm& obj);
