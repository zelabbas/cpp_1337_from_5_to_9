/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 21:45:46 by zelabbas          #+#    #+#             */
/*   Updated: 2024/07/16 13:59:08 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

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
		Form test3;
		Bureaucrat bureaucrat("saim", 1);
		Form zak("zak", 1, 34);
		Form test = zak;
		bureaucrat.signForm(zak);
		zak.beSigned(bureaucrat);
		std::cout << test3;
		std::cout << zak;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Form ichou("ichou", 151, 49);
	}
	catch (const std::exception& e)
	{
			std::cerr << e.what() << std::endl;
	}
	return 0;
}