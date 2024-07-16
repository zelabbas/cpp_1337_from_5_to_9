/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 16:59:39 by zelabbas          #+#    #+#             */
/*   Updated: 2024/07/16 11:26:31 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void) : name(""), gradeRequiredtoSign(1), gradeRequiredtoExcute(1)
{
	this->_signed = false;
}

Form::Form(const std::string& _name, int gradeSign, int gradeExcute): name(_name), \
	gradeRequiredtoSign(gradeSign), gradeRequiredtoExcute(gradeExcute)
{
	this->_signed = false;
	if (this->gradeRequiredtoSign < 1 || this->gradeRequiredtoExcute < 1)
		throw GradeTooHighException();
	else if (this->gradeRequiredtoSign > 150 || this->gradeRequiredtoExcute > 150)
		throw GradeTooLowException();
}

Form::Form(const Form& obj) : name(obj.name), gradeRequiredtoSign(obj.gradeRequiredtoSign), gradeRequiredtoExcute(obj.gradeRequiredtoExcute)
{
	this->_signed = obj._signed;
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
		throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& out, const Form& obj)
{
	out << "Form " << obj.getName() << ", Sign Status: " << (obj.isSigned() ? "Signed" : "Not Signed")
	<< ", Grade Required to Sign: " << obj.getGradeRequiredtoSign()
	<< ", Grade Required to Execute: " << obj.getGradeRequiredtoExcute() << std::endl;
	return out;
}
