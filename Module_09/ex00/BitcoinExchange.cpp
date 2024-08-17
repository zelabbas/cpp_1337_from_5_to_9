/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 15:29:38 by zelabbas          #+#    #+#             */
/*   Updated: 2024/08/17 21:30:59 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
	std::cout << "called constructor by default!" << std::endl;
}

BitcoinExchange::~BitcoinExchange() {
	std::cout << "called destructor!" << std::endl;
}

void	BitcoinExchange::parseFileName(const std::string& fileName) {
	std::string target = ".txt";
	std::string	fileExtension;
	if (fileName.size() < 4)
		throw InvalidFileName;
	fileExtension = fileName.substr(fileName.size() - 4);
	if (fileExtension != target)
		throw InvalidFileName;
}

void	BitcoinExchange::OpenFile(const std::string& FileName)
{
	infile.open(FileName);
	if (!infile.is_open())
		throw ErrorOpenFile;
	dataBase.open("data.csv");
	if (!dataBase.is_open()) {
		infile.close();
		throw ErrorOpenFile;
	}
}
std::string	BitcoinExchange::trimString(const std::string& str) {
	size_t start = 0;
	size_t end = str.size();

	while (start < end && std::isspace(str[start])) {
		++start;
	}

	while (end > start && std::isspace(str[end - 1])) {
		--end;
	}

	return str.substr(start, end - start);
}

bool	BitcoinExchange::validValue(const std::string& _valueStr) {
	std::stringstream strFloat(_valueStr);
	strFloat >> _value;
	return !strFloat.fail() && strFloat.eof();
}

void	BitcoinExchange::displayError(const std::string& _line, int _nError) {
	switch (_nError)
	{
		case 0:
			std::cerr << "Error : bad input => " << _line << std::endl;
			break;
		case 1:
			std::cerr << "Error: not a positive number." << std::endl;
			break;
		case 2:
			std::cerr << "Error: too large a number." <<  std::endl;
			break;
		default:
			std::cout << "not a vlide number Error be careful!" << std::endl;
	}
}

void	BitcoinExchange::parseLine(const std::string& _line) {
	std::string	_date;
	std::string	_valueStr;
	std::stringstream str;

	size_t	delimiterPos = _line.find('|');
	if (delimiterPos == std::string::npos)
		return (displayError(_line, 0));
	_date = _line.substr(0, delimiterPos);
	_valueStr = _line.substr(delimiterPos + 1);
	_date = trimString(_date);
	_valueStr = trimString(_valueStr);
	if (!validValue(_valueStr))
		return (displayError(_line, 0));
	if (_value < 0)
		return (displayError(_line, 1));
	if (_value > 1000)
		return (displayError(_line, 2));
	std::cout << _date << " | " << _valueStr << std::endl;
}

void	BitcoinExchange::readAndParseData(void) {
	std::string	line;

	getline(infile, line);
	line = trimString(line);
	if (line != "date | value") {
		std::cerr << "invalide data" << std::endl;
		exit(1);
	}
	while (getline(infile, line))
	{
		parseLine(line);
	}
}

const char*	BitcoinExchange::InvalidFileName::what() const throw() {
	return ("Invalide File Name!");
}

const char*	BitcoinExchange::Erroropenfile::what() const throw() {
	return ("can't open the file!");
}



