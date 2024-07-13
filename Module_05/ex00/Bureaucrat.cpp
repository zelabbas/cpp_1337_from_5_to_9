/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 21:44:30 by zelabbas          #+#    #+#             */
/*   Updated: 2024/07/13 16:30:13 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : name(""), grade(1)
{

}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& obj) : name(obj.name)
{
	this->grade = obj.grade;
}

Bureaucrat::~Bureaucrat(void)
{

}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& obj)
{
	if (this != &obj)
		this->grade = obj.grade;
	return (*this);
}

const std::string& Bureaucrat::getName(void) const
{
	return (this->name);
}

int	Bureaucrat::getGrade(void) const
{
	return (this->grade);
}


void	Bureaucrat::incrementGrade(void)
{
	if (grade <= 1)
		throw GradeTooHighException();
	this->grade--;
}

void	Bureaucrat::decrementGrade(void)
{
	if (grade >= 150)
		throw GradeTooLowException();
	this->grade++;
}

std::ostream& operator << (std::ostream &out, const Bureaucrat &c)
{
	out << c.getName() << ", bureaucrat grade " << c.getGrade() << std::endl;
	return (out);
}