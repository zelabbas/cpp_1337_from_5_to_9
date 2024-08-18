/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 15:38:15 by zelabbas          #+#    #+#             */
/*   Updated: 2024/08/18 14:53:33 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>

void	f(){system("leaks btc");}

int main(int ac, char **av) {

	(void)av;
	atexit(f);
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
		test.loadDataFromDataBase();
		test.readAndParseData();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "---------------------------------------------------" << std::endl;
	std::map<std::string, float>::iterator it = test.dataBaseMap.begin();

    // Iterate through the map and print the elements
    while (it != test.dataBaseMap.end()) {
        std::cout << it->first
             << "," << it->second << std::endl;
        ++it;
    }
}