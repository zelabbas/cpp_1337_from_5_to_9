/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 21:45:46 by zelabbas          #+#    #+#             */
/*   Updated: 2024/07/16 13:39:57 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

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
		Bureaucrat saim("saim", 1);
		Bureaucrat test = saim;
		Bureaucrat zak("zak", 3);

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