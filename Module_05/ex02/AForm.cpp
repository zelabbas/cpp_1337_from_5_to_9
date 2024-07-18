/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 16:59:39 by zelabbas          #+#    #+#             */
/*   Updated: 2024/07/18 09:33:32 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(void) : name("defaultName"), gradeRequiredtoSign(150), gradeRequiredtoExcute(150)
{
	this->_signed = false;
}

AForm::AForm(const std::string& _name, int gradeSign, int gradeExcute): name(_name), \
	gradeRequiredtoSign(gradeSign), gradeRequiredtoExcute(gradeExcute)
{
	this->_signed = false;
	if (this->gradeRequiredtoSign < 1 || this->gradeRequiredtoExcute < 1)
		throw GradeTooHighException;
	else if (this->gradeRequiredtoSign > 150 || this->gradeRequiredtoExcute > 150)
		throw GradeTooLowException;
}

AForm::AForm(const AForm& obj) : name(obj.name), gradeRequiredtoSign(obj.gradeRequiredtoSign), gradeRequiredtoExcute(obj.gradeRequiredtoExcute)
{
	*this = obj;
}

AForm::~AForm(void)
{
	
}

AForm& AForm::operator=(const AForm& obj)
{
	if (this != &obj)
		this->_signed = obj._signed;
	return (*this);
}

const std::string& AForm::getName(void) const
{
	return (this->name);	
}

bool	AForm::isSigned(void) const
{
	return (this->_signed);
}

int	AForm::getGradeRequiredtoSign(void) const
{
	return (this->gradeRequiredtoSign);
}

int	AForm::getGradeRequiredtoExcute(void) const
{
	return (this->gradeRequiredtoExcute);
}

void	AForm::beSigned(const Bureaucrat& obj)
{
	if (obj.getGrade() <= this->gradeRequiredtoSign)
		this->_signed = true;
	else
		throw GradeTooLowException;
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "AForm: Grade too high!";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "AForm: Grade too low!";
}

std::ostream& operator<<(std::ostream& out, const AForm& obj)
{
	out << "Form " << obj.getName() << ", Sign Status: " << (obj.isSigned() ? "Signed" : "Not Signed")
	<< ", Grade Required to Sign: " << obj.getGradeRequiredtoSign()
	<< ", Grade Required to Execute: " << obj.getGradeRequiredtoExcute() << std::endl;
	return out;
}
