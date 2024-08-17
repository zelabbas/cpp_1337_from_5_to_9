/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 15:29:35 by zelabbas          #+#    #+#             */
/*   Updated: 2024/08/17 21:33:11 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sstream>

class BitcoinExchange
{
	private:
		/* data */
		std::ifstream	infile;
		std::ifstream	dataBase;
		float			_value;
		std::string		trimString(const std::string& str);
		void			parseLine(const std::string& _line);
		bool			validDate(const std::string& _date);
		bool			validValue(const std::string& _value);
		void			displayError(const std::string& _line, int _nError);
	public:
		BitcoinExchange(/* args */);
		~BitcoinExchange();
		void 	parseFileName(const std::string& FileName);
		void	OpenFile(const std::string& FileName);
		void	readAndParseData(void);
		class	InvalidFileName: public std::exception
		{
			public:
				const char* what() const throw();
		} InvalidFileName;
		class	Erroropenfile: public std::exception
		{
			public:
				const char* what() const throw();
		} ErrorOpenFile;
};
