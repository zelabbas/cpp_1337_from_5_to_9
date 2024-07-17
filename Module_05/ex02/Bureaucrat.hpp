/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 21:44:27 by zelabbas          #+#    #+#             */
/*   Updated: 2024/07/17 18:27:09 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class AForm;

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
		void	signForm(AForm&) const;
		// class exception gradetoo_high
		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw()
				{
					return "Bureaucrat: Grade too high!";
				}
		};
		// class exception gradetoo_low
		class GradeTooLowException : public std::exception
		{
		 	public:
				const char* what() const throw()
				{
					return "Bureaucrat: Grade too low!";
				}
		};
};

std::ostream& operator << (std::ostream &out, const Bureaucrat &c);

#endif