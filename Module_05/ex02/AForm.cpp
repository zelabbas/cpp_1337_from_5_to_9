/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 16:59:39 by zelabbas          #+#    #+#             */
/*   Updated: 2024/07/17 18:29:45 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(void) : name(""), gradeRequiredtoSign(1), gradeRequiredtoExcute(1)
{
	this->_signed = false;
}

AForm::AForm(const std::string& _name, int gradeSign, int gradeExcute): name(_name), \
	gradeRequiredtoSign(gradeSign), gradeRequiredtoExcute(gradeExcute)
{
	this->_signed = false;
	if (this->gradeRequiredtoSign < 1 || this->gradeRequiredtoExcute < 1)
		throw GradeTooHighException();
	else if (this->gradeRequiredtoSign > 150 || this->gradeRequiredtoExcute > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm& obj) : name(obj.name), gradeRequiredtoSign(obj.gradeRequiredtoSign), gradeRequiredtoExcute(obj.gradeRequiredtoExcute)
{
	this->_signed = obj._signed;
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
		throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& out, const AForm& obj)
{
	out << "Form " << obj.getName() << ", Sign Status: " << (obj.isSigned() ? "Signed" : "Not Signed")
	<< ", Grade Required to Sign: " << obj.getGradeRequiredtoSign()
	<< ", Grade Required to Execute: " << obj.getGradeRequiredtoExcute() << std::endl;
	return out;
}
