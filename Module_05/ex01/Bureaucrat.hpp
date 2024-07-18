/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 21:44:27 by zelabbas          #+#    #+#             */
/*   Updated: 2024/07/18 09:24:04 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include "Form.hpp"

class Form;

class Bureaucrat
{
	private:
		const std::string	name;
		int					grade;
	public:
		// constroctors
		Bureaucrat(void);
		Bureaucrat(const std::string&, int);
		Bureaucrat(const Bureaucrat&);
		~Bureaucrat(void);

		// operator = 
		Bureaucrat& operator=(const Bureaucrat&);

		// getters:
		const std::string&	getName(void) const;
		int					getGrade() const;

		// method
		void	incrementGrade(void);
		void	decrementGrade(void);
		void	signForm(Form&);
		
		// class exception gradetoo_high
		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw();
		} GradeTooHighException;
		// class exception gradetoo_low
		class GradeTooLowException : public std::exception
		{
		 	public:
				const char* what() const throw();
		} GradeTooLowException;
};

std::ostream& operator << (std::ostream &out, const Bureaucrat &c);

#endif