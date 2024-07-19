/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 21:45:46 by zelabbas          #+#    #+#             */
/*   Updated: 2024/07/19 11:52:35 by zelabbas         ###   ########.fr       */
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
		Bureaucrat bureaucrat("saim", 1);
		RobotomyRequestForm roboto("roboto");
		
		bureaucrat.signForm(roboto);
		roboto.execute(bureaucrat);
		std::cout << roboto;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	try
	{
		Bureaucrat bureaucrat("zak", 1);
		ShrubberyCreationForm shrubbery("shrubbery");
		bureaucrat.signForm(shrubbery);
		shrubbery.execute(bureaucrat);
		std::cout << shrubbery;
	}
	catch (const std::exception& e)
	{
			std::cerr << e.what() << std::endl;
	}

	try
	{
		std::srand(std::time(nullptr));
		Bureaucrat bureaucrat("zak", 4);
		PresidentialPardonForm presidential("presidential");
		bureaucrat.signForm(presidential);
		presidential.execute(bureaucrat);
		std::cout << presidential;
	}
	catch (const std::exception& e)
	{
			std::cerr << e.what() << std::endl;
	}
	return 0;
}