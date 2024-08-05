/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 12:21:27 by zelabbas          #+#    #+#             */
/*   Updated: 2024/08/05 12:52:05 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

int main(int ac, char **av)
{
	(void)av;

	if (ac != 1)
	{
		std::cerr << "Error usage: ./iter" << std::endl;
		return (1);
	}

	int a[5] = { 10, 50, 30, 40, 20 };
	size_t n = sizeof(a) / sizeof(a[0]);
	iter(a, n, swap <int>);
	for (size_t i = 0; i < n; i++)
		std::cout << a[i] << " ";
	std::cout << std::endl;

	std::string s[5] = { "hey", "hello", "who", "son", "clear" };
	size_t len = sizeof(s) / sizeof(s[0]);
	iter(s, len, swap <std::string>);
	for (size_t i = 0; i < len; i++)
		std::cout << s[i] << " ";
	std::cout << std::endl;
}