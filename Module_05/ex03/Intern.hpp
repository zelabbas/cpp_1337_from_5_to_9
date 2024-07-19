/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 21:24:27 by zelabbas          #+#    #+#             */
/*   Updated: 2024/07/19 10:42:09 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	private:
		
	public:
		Intern(void);
		Intern(const Intern&);
		~Intern();

		Intern& operator=(const Intern&);

		AForm*	makeForm(const std::string&, const std::string&);

		class FormNotExistException : public std::exception
		{
			public:
				const char *what() const throw();
		} FormNotExistException;

		class FailedAllocateMemoryException: public std::exception
		{
			public:
				const char* what() const throw();
		} FailedAllocateMemoryException;
};
