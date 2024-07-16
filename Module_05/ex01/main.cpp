/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 21:45:46 by zelabbas          #+#    #+#             */
/*   Updated: 2024/07/16 11:31:29 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(int ac, char **av)
{
	(void)av;
	if (ac != 1)
	{
		std::cerr << "the program don't accepte arguments" << std::endl;
		return (1);
	}
	try
	{
		Form TEST("ZIKO",4, 2);
		Bureaucrat saim("saim", 1);
		Bureaucrat test = saim;
		Bureaucrat zak("zak", 3);
		TEST.beSigned(test);
		test.signForm(TEST);
		std::cout << TEST;
		std::cout << zak;
		std::cout << saim;
		std::cout << test;
		saim.incrementGrade();
		std::cout << saim << std::endl;
		saim.incrementGrade();
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Bureaucrat ichou("ichou", 151);
	}
	catch (const std::exception& e) {
			std::cerr << e.what() << std::endl;
	}
	return 0;
}