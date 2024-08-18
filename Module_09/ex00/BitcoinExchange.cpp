/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 15:29:38 by zelabbas          #+#    #+#             */
/*   Updated: 2024/08/18 21:48:23 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
	// std::cout << "called constructor by default!" << std::endl;
}

BitcoinExchange::~BitcoinExchange() {
	// std::cout << "called destructor!" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& _obj) {
	if (this != &_obj)
		*this = _obj;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& _obj) {
	if (this != &_obj) {
		dataBaseMap = _obj.dataBaseMap;
	}
	return (*this);
}

void	BitcoinExchange::parseFileName(const std::string& fileName) {
	std::string target = ".txt";
	std::string	fileExtension;
	if (fileName.size() < 4)
	{
		std::cerr << fileName << ": ";
		throw InvalidFileName;
	}
	fileExtension = fileName.substr(fileName.size() - 4);
	if (fileExtension != target) {
		std::cerr << fileName << ": ";
		throw InvalidFileName;
	}
}

void	BitcoinExchange::OpenFile(const std::string& FileName)
{
	infile.open(FileName);
	if (!infile.is_open()) 
	{
		std::cerr << FileName << ": "; 
		throw ErrorOpenFile;
	}
	dataBase.open("data.csv");
	if (!dataBase.is_open()) {
		infile.close();
		std::cerr << "data.csv: ";
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

bool	BitcoinExchange::validValue(const std::string& _valueStr) {
	std::stringstream strFloat(_valueStr);
	strFloat >> _value;
	return !strFloat.fail() && strFloat.eof();
}

bool	BitcoinExchange::validYearMonthDay(const std::string& _yStr, const std::string& _mStr, const std::string& _dStr) {
	int _year, _month, _day;
	bool isLeap;
	const int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	std::stringstream yearInt(_yStr);
	std::stringstream monthInt(_mStr);
	std::stringstream dayInt(_dStr);
	
	yearInt >> _year;
	monthInt >> _month;
	dayInt >> _day;
	isLeap = false;

	if (_month < 1 || _month > 12)
		return (false);
	if (_month == 2) {
			isLeap = (_year % 4 == 0 && _year % 100 != 0) || (_year % 400 == 0);
		if (_day > (isLeap ? 29 : 28))
			return false;
	}
	else if (_day > daysInMonth[_month - 1])
		return false;
	return (!yearInt.fail() && !monthInt.fail() && !dayInt.fail()
		&& yearInt.eof() && monthInt.eof() && dayInt.eof());
}

bool	BitcoinExchange::validDate(const std::string& _date) {
	std::string	yearStr;
	std::string	monthStr;
	std::string	dayStr;
	
	if (_date.size() != 10 || _date[4] != '-' || _date[7] != '-' )
		return (false);
	yearStr = _date.substr(0, 4);
	monthStr = _date.substr(5, 2);
	dayStr = _date.substr(8, 2);
	if (!validYearMonthDay(yearStr, monthStr, dayStr))
		return (false);
	// std::cout << "here: " + yearStr << "-" << monthStr << "-" <<dayStr  << std::endl;
	return (true);
}

bool	BitcoinExchange::parseLine(const std::string& _line) {
	// std::string	_date;
	std::string	_valueStr;
	size_t		delimiterPos;

	delimiterPos = _line.find('|');
	if (delimiterPos == std::string::npos)
		return (displayError(_line, 0), false);
	_date = _line.substr(0, delimiterPos);
	_valueStr = _line.substr(delimiterPos + 1);
	_date = trimString(_date);
	_valueStr = trimString(_valueStr);
	if (!validDate(_date) || !validValue(_valueStr))
		return (displayError(_line, 0), false);
	if (_value < 0)
		return (displayError(_line, 1), false);
	if (_value > 1000)
		return (displayError(_line, 2), false);
	return (true);
}

void	BitcoinExchange::addToDataBaseMap(const std::string& _str, size_t _posDelimiter) {
	std::string	_date;
	std::string	_rate;
	float		_rateValue;

	_date = _str.substr(0, _posDelimiter);
	_rate = _str.substr(_posDelimiter + 1);
	_date = trimString(_date);
	_rate = trimString(_rate);
	std::stringstream	rateFloat(_rate);
	rateFloat >> _rateValue;
	if (rateFloat.fail() || !rateFloat.eof())
	{
		infile.close();
		dataBase.close();
		throw ErrorInvalidData;
	}
	dataBaseMap[_date] = _rateValue;
}

void	BitcoinExchange::loadDataFromDataBase(void) {
	std::string	line;
	size_t		delimiterPos;

	getline(dataBase, line);
	line = trimString(line);
	if (line != "date,exchange_rate")
		throw	ErrorInvalidData;
	while (getline(dataBase, line))
	{
		delimiterPos = line.find(',');
		if (delimiterPos == std::string::npos)
		{
			infile.close();
			dataBase.close();
			throw ErrorInvalidData;
		}
		addToDataBaseMap(line, delimiterPos);
	}
	dataBase.close();
}

void	BitcoinExchange::findClosestLowerDate(const std::string& inputDate)	{
	std::map<std::string, float>::const_iterator it;

	it = dataBaseMap.lower_bound(inputDate);
	if (it != dataBaseMap.end() && it->first == inputDate)
		std::cout << inputDate << " => " << _value << " = " << it->second * _value << std::endl;
	else {
		if (it != dataBaseMap.begin()) {
			--it;
			if (it->first < inputDate)
				std::cout << inputDate << " => " << _value << " = " << it->second * _value << std::endl;
			else
				std::cerr << "No suitable date found in the database for: " << inputDate << std::endl;
		}
		else
			std::cerr << "No suitable date found in the database for: " << inputDate << std::endl;
	}
	
}

void	BitcoinExchange::readAndParseData(void) {
	std::string	line;

	getline(infile, line);
	line = trimString(line);
	if (line != "date | value")
		throw ErrorInvalidData;
	while (getline(infile, line))
	{
		if (parseLine(line))
			findClosestLowerDate(_date);
	}
	infile.close();
}

const char*	BitcoinExchange::InvalidFileName::what() const throw() {
	return ("Invalide File Name!");
}

const char*	BitcoinExchange::Erroropenfile::what() const throw() {
	return ("can't open the file!");
}

const char*	BitcoinExchange::ErrorInvalidData::what() const throw() {
	return ("Invalide Data input!");
}