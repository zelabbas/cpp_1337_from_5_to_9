/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 13:54:35 by zelabbas          #+#    #+#             */
/*   Updated: 2024/08/19 21:24:43 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av) {

	(void)av;
	std::string	_str;
	RPN	test;
	RPN	test2;
	if (ac != 2) {
		std::cerr << "Error usage: ./RPN 'arg'" << std::endl;
		return (1);
	}
	_str = static_cast<const std::string> (av[1]);
	try
	{
		test.parseArg(_str);
		test.ReversePolish(_str);
		test2 = test;
		test2.ReversePolish(_str);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << " => "<< av[1] << std::endl;
	}
}