/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 15:38:15 by zelabbas          #+#    #+#             */
/*   Updated: 2024/08/20 11:14:00 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av) {

	BitcoinExchange test;
	BitcoinExchange test2;
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
		test2 = test;
		test.closeFds();
		test2.OpenFile(fileName);
		test2.readAndParseData();
		test2.closeFds();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}