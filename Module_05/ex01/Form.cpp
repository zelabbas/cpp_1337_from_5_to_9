/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 16:59:39 by zelabbas          #+#    #+#             */
/*   Updated: 2024/07/18 09:24:34 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void) : name("defaultName"), gradeRequiredtoSign(150), gradeRequiredtoExcute(150)
{
	this->_signed = false;
}

Form::Form(const std::string& _name, int gradeSign, int gradeExcute): name(_name), \
	gradeRequiredtoSign(gradeSign), gradeRequiredtoExcute(gradeExcute)
{
	this->_signed = false;
	if (this->gradeRequiredtoSign < 1 || this->gradeRequiredtoExcute < 1)
		throw GradeTooHighException;
	else if (this->gradeRequiredtoSign > 150 || this->gradeRequiredtoExcute > 150)
		throw GradeTooLowException;
}

Form::Form(const Form& obj) : name(obj.name), gradeRequiredtoSign(obj.gradeRequiredtoSign), gradeRequiredtoExcute(obj.gradeRequiredtoExcute)
{
	*this = obj;
}

Form::~Form(void)
{
	
}

Form& Form::operator=(const Form& obj)
{
	if (this != &obj)
		this->_signed = obj._signed;
	return (*this);
}

const std::string& Form::getName(void) const
{
	return (this->name);	
}

bool	Form::isSigned(void) const
{
	return (this->_signed);
}

int	Form::getGradeRequiredtoSign(void) const
{
	return (this->gradeRequiredtoSign);
}

int	Form::getGradeRequiredtoExcute(void) const
{
	return (this->gradeRequiredtoExcute);
}

void	Form::beSigned(const Bureaucrat& obj)
{
	if (obj.getGrade() <= this->gradeRequiredtoSign)
		this->_signed = true;
	else
		throw GradeTooLowException;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "Form: Grade too high!";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Form: Grade too low!";
}

std::ostream& operator<<(std::ostream& out, const Form& obj)
{
	out << "Form " << obj.getName() << ", Sign Status: " << (obj.isSigned() ? "Signed" : "Not Signed")
	<< ", Grade Required to Sign: " << obj.getGradeRequiredtoSign()
	<< ", Grade Required to Execute: " << obj.getGradeRequiredtoExcute() << std::endl;
	return out;
}
