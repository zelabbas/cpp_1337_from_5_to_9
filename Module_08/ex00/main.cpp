/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 12:07:53 by zelabbas          #+#    #+#             */
/*   Updated: 2024/08/09 10:25:28 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "easyfind.hpp"
#include <algorithm>
#include <list>
#include <deque>
#include <set>

int main(int ac, char **av)
{
	(void)av;
	if (ac != 1)
	{
		std::cerr << "Error usage: ./easyfind!" << std::endl;
		return (1);
	}

	int vecArray[] = {1, 2, 3, 4, 6};
	std::vector<int> vec(vecArray, vecArray + 5);

	// Initialize list
	std::list<int> lst;
	lst.push_back(10);
	lst.push_back(20);
	lst.push_back(30);
	lst.push_back(40);
	lst.push_back(50);

	// Initialize deque
	std::deque<int> deq;
	deq.push_back(100);
	deq.push_back(200);
	deq.push_back(300);
	deq.push_back(400);
	deq.push_back(500);

	// Initialize set
	std::set<int> st;
	st.insert(1000);
	st.insert(2000);
	st.insert(3000);
	st.insert(4000);
	st.insert(5000);

	try
	{
		// Using easyfind with a vector
		std::vector<int>::iterator itVec = easyfind(vec, 3);
		std::cout << "Found in vector: " << *itVec << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		// Using easyfind with a list
		std::list<int>::iterator itList = easyfind(lst, 30);
		std::cout << "Found in list: " << *itList << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		// Using easyfind with a deque
		std::deque<int>::iterator itDeq = easyfind(deq, 400);
		std::cout << "Found in deque: " << *itDeq << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		// Using easyfind with a set
		std::set<int>::iterator itSet = easyfind(st, 3000);
		std::cout << "Found in set: " << *itSet << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}

