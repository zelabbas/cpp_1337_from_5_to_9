/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 21:45:46 by zelabbas          #+#    #+#             */
/*   Updated: 2024/07/19 15:01:21 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int main(int ac, char **av)
{
	(void)av;
	if (ac != 1)
	{
		std::cerr << "the program doesn't accepte any arguments" << std::endl;
		return (1);
	}
	try
	{
		Bureaucrat bureaucrat("zak", 1);
		Intern intern;
		AForm *form1;
		AForm *form2;
		form1 = intern.makeForm("Roboto", "Bender");
		form2 = intern.makeForm("Shrubbery", "saim");
		try
		{
			bureaucrat.signForm(*form1);
			bureaucrat.signForm(*form2);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			bureaucrat.executeForm(*form1);
			form2->execute(bureaucrat);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		delete form1;
		delete form2;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}