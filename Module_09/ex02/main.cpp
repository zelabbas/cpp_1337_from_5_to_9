/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 11:22:17 by zelabbas          #+#    #+#             */
/*   Updated: 2024/08/21 14:16:42 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av) {

	int	i;
	PmergeMe	test;
	clock_t		startTimeV;
	clock_t		endTimeV;
	clock_t		startTimeD;
	clock_t		endTimeD;
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
		startTimeV = clock();
		test.MergeSortVector();
		endTimeV = clock();
		startTimeD = clock();
		test.MergeSortDeque();
		endTimeD = clock();
		std::cout << "After: ";
		test.displayElements();
		std::cout << "time is : " << static_cast<double>(endTimeV - startTimeV / CLOCKS_PER_SEC) << std::endl;
		std::cout << "time is : " << static_cast<double>(endTimeD - startTimeD / CLOCKS_PER_SEC) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return (0);
}