/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 12:21:27 by zelabbas          #+#    #+#             */
/*   Updated: 2024/08/06 18:56:33 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>


void	plusOne(int &nbr)
{
	nbr += 1;
}

void	_toUpper(std::string& str)
{
	for (size_t i = 0; i < str.size(); i++)
	{
		str[i] = std::toupper(static_cast<int>(str[i]));
	}
	
}

int main(int ac, char **av)
{
	(void)av;

	if (ac != 1)
	{
		std::cerr << "Error usage: ./iter" << std::endl;
		return (1);
	}
	try 
	{
		int a[5] = { 10, 50, 30, 40, 20 };
		iter(a, 5, plusOne);
		for (size_t i = 0; i < 5; i++)
			std::cout << a[i] << " ";
		std::cout << std::endl;
	
		std::string s[5] = { "hey", "hello", "who", "son", "clear" };
		iter(s, 5, _toUpper);
		for (size_t i = 0; i < 5; i++)
			std::cout << s[i] << " ";
		std::cout << std::endl;
	}catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
