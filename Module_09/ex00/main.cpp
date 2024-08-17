/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 15:38:15 by zelabbas          #+#    #+#             */
/*   Updated: 2024/08/17 21:07:08 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>

void	f(){system("leaks btc");}

int main(int ac, char **av) {

	(void)av;
	// atexit(f);
	BitcoinExchange test;
	std::string		fileName;
	
	if (ac != 2) {
		std::cerr << "Error usage: ./bitcoinExchange file" << std::endl;
		return (1);
	}

	fileName = static_cast<const std::string>(av[1]);
	try
	{	
		test.parseFileName(fileName);
		test.OpenFile(fileName);
		test.readAndParseData();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}