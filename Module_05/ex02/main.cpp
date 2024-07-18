/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 21:45:46 by zelabbas          #+#    #+#             */
/*   Updated: 2024/07/18 09:32:07 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

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
		AForm zak("zak", 1, 34);
		AForm test = zak;
		bureaucrat.signForm(zak);
		zak.beSigned(bureaucrat);
		std::cout << zak;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		AForm ichou("ichou", 150, 49);
		std::cout << ichou;
	}
	catch (const std::exception& e)
	{
			std::cerr << e.what() << std::endl;
	}
	return 0;
}