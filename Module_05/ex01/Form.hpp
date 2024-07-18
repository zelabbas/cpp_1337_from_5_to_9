/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 16:59:36 by zelabbas          #+#    #+#             */
/*   Updated: 2024/07/18 09:10:58 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Bureaucrat.hpp"
class Bureaucrat;

class Form
{
	private:
		const std::string	name;
		bool				_signed;
		const int			gradeRequiredtoSign;
		const int			gradeRequiredtoExcute;
		
	public:
		Form();
		Form(const std::string&, int, int);
		Form(const Form&);
		~Form();

		Form& operator= (const Form&);

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

std::ostream& operator << (std::ostream& out, const Form& obj);
