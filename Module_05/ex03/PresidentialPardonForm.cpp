/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 09:36:33 by zelabbas          #+#    #+#             */
/*   Updated: 2024/07/18 18:51:07 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("PresidentForm", 25, 5)
{
	this->target = "defaultTarget";
}

PresidentialPardonForm::PresidentialPardonForm(const std::string _target) : AForm("PresidentForm", 25, 5)
{
	this->target = _target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& PresidentForm) : AForm(PresidentForm.getName(), PresidentForm.getGradeRequiredtoSign(), PresidentForm.getGradeRequiredtoExcute())
{
	*this = PresidentForm;	
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	
}

PresidentialPardonForm&  PresidentialPardonForm::operator=(const PresidentialPardonForm& PresidentForm)
{
	if (this != &PresidentForm)
		this->target = PresidentForm.target;
	return (*this);
}

void	PresidentialPardonForm::PresidentialPardonFormAction(void) const
{
	std::cout << this->target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	checkExecution(executor);
	PresidentialPardonFormAction();
}

const std::string&  PresidentialPardonForm::getTarget(void) const
{
	return (this->target);
}