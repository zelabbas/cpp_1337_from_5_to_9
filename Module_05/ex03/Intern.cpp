/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 21:24:30 by zelabbas          #+#    #+#             */
/*   Updated: 2024/07/19 10:49:38 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void)
{
	
}

Intern::Intern(const Intern& intern)
{
	if (this != &intern)
		*this = intern;
}

Intern::~Intern(void)
{

}

Intern& Intern::operator=(const Intern& intern)
{
	(void)intern;
	return (*this);
}

AForm* Intern::makeForm(const std::string& _name, const std::string& _target)
{
	AForm *ptr;
	std::string classesName[] = {"Shrubbery", "Roboto", "Presidential"};

	int i = -1;
	int found = -1;
	while (++i < 3)
	{
		if (classesName[i] == _name)
			found = i;
	}
	switch (found)
	{
		case 0:
			ptr = new ShrubberyCreationForm(_target);
			break;
		case 1:
			ptr = new RobotomyRequestForm(_target);
			break;
		case 2:
			ptr = new PresidentialPardonForm(_target);
			break;
		default:
			throw FormNotExistException;
	}
	if (!ptr)
		throw FailedAllocateMemoryException;
	return (ptr);
}

const char* Intern::FormNotExistException::what() const throw()
{
	return ("Form not found!");
}

const char* Intern::FailedAllocateMemoryException::what() const throw()
{
	return ("Failed to allocate memory!");
}