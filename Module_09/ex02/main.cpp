/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 11:22:17 by zelabbas          #+#    #+#             */
/*   Updated: 2024/08/20 14:12:05 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av) {

	int	i;
	PmergeMe	test;
	if (ac == 1) {
		std::cerr << "Error usage: ./PmergeMe arg1 arg2 ..." << std::endl;
		return (1);
	}
	try
	{
		i = 1;
		while (i < ac)
		{
			test.ParseArgAndStorIt(static_cast<std::string> (av[i]));
			i++;
		}
		std::cout << "Before: ";
		test.displayElements();
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return (0);
}