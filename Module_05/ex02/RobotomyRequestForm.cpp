/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 09:36:38 by zelabbas          #+#    #+#             */
/*   Updated: 2024/07/18 19:16:07 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("Robot", 72, 45)
{
	this->target = "defaultTarget";
}

RobotomyRequestForm::RobotomyRequestForm(const std::string _target): AForm("Robot", 72, 45)
{
	this->target = _target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& Robot) : AForm(Robot.getName(), Robot.getGradeRequiredtoSign(), Robot.getGradeRequiredtoExcute())
{
	*this = Robot;	
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	
}

RobotomyRequestForm&  RobotomyRequestForm::operator=(const RobotomyRequestForm& Robot)
{
	if (this != &Robot)
		this->target = Robot.target;
	return (*this);
}


const std::string& RobotomyRequestForm::getTarget(void) const
{
	return (this->target);
}

void	RobotomyRequestForm::RobotomyRequestFormAction(void) const
{
	int n;
	std::cout << "Drilling noises" << std::endl;
	n = std::rand() % 3;
	std::cout << n << std::endl;
	
	if (!n)
		std::cout << this->target << " has been robotomized successfully.\n";
	else
		std::cout << "The robotomy of " << this->target << " failed.\n";
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	checkExecution(executor);
	RobotomyRequestFormAction();
}