/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 10:31:24 by zelabbas          #+#    #+#             */
/*   Updated: 2024/08/10 14:39:08 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Span.hpp"

int main(int ac, char **av) {

	(void)av;

	if (ac != 1)
	{
		std::cerr << "Error usage: ./span!" << std::endl;
		return (1);
	}
	Span a(2);
	try
	{
		a.addNumber(1);
		std::cout << "here1\n";
		a.addNumber(2);
		std::cout << "here2\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	Span sp = Span(10000);
	sp.FillArray();
	// sp.addNumber(6);
	// sp.addNumber(10);
	// sp.addNumber(17);
	// sp.addNumber(9);
	// sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}