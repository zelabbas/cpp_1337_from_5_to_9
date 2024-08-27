/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 11:22:17 by zelabbas          #+#    #+#             */
/*   Updated: 2024/08/27 20:52:23 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// Function to calculate time difference in seconds
double getTimeDifferenceInSeconds(const struct timeval& start, const struct timeval& end) {
	return (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;
}

int main(int ac, char **av) {
	int i;
	PmergeMe test;
	struct timeval startTimeV, endTimeV;
	struct timeval startTimeD, endTimeD;

	if (ac == 1) {
		std::cerr << "Error usage: ./PmergeMe arg1 arg2 ..." << std::endl;
		return 1;
	}
	try {
		i = 1;
		while (i < ac) {
			test.ParseArgAndStorIt(static_cast<std::string>(av[i]));
			i++;
		}
		std::cout << "Before: ";
		test.displayElementsDeque();

		gettimeofday(&startTimeD, NULL);
		test.FordJohnsonDeque();
		gettimeofday(&endTimeD, NULL);

		gettimeofday(&startTimeV, NULL);
		test.FordJohnsonVector();
		gettimeofday(&endTimeV, NULL);

		std::cout << "After: ";
		test.displayElementsVector();
		std::cout << "Vector time: " << getTimeDifferenceInSeconds(startTimeV, endTimeV) << " seconds" << std::endl;
		std::cout << "Deque time: " << getTimeDifferenceInSeconds(startTimeD, endTimeD) << " seconds" << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return 0;
}