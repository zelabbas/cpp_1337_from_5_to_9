/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 15:29:35 by zelabbas          #+#    #+#             */
/*   Updated: 2024/08/20 11:12:14 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <fstream>
#include <map>
#include <cstdlib>
#include <sstream>

class BitcoinExchange
{
	private:
		/* data */
		std::ifstream					infile;
		std::ifstream					dataBase;
		float							_value;
		std::string						_date;
		std::map<std::string, float>	dataBaseMap;
		std::string						trimString(const std::string& str);
		bool							parseLine(const std::string& _line);
		bool							isValidYearMonthDay(const std::string& _yStr,
											const std::string& _mStr, const std::string& _dStr);
		bool							isValidDate(const std::string& _date);
		bool							isValidValue(const std::string& _value);
		void							addToDataBaseMap(const std::string& _str, size_t _posDelimiter);
		void							findClosestLowerDate(const std::string& inputDate);
		void							displayError(const std::string& _line, int _nError);
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& _obj);
		~BitcoinExchange();
		BitcoinExchange& operator=(const BitcoinExchange& _obj);
		void 	parseFileName(const std::string& FileName);
		void	OpenFile(const std::string& FileName);
		void	loadDataFromDataBase(void);
		void	readAndParseData(void);
		void	closeFds(void);
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
		class	ErrorInvalidData: public std::exception
		{
			public:
				const char* what() const throw();
		} ErrorInvalidData;
};
