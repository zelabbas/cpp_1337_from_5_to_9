/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 11:20:51 by zelabbas          #+#    #+#             */
/*   Updated: 2024/08/20 16:52:27 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {
	std::cout << "constructor by default called" << std::endl;
}

PmergeMe::~PmergeMe() {
	std::cout << "Destructor called" << std::endl; 
}

bool	PmergeMe::isPlusOrMinus(char c) {
	return (c == '-' || c == '+');
}

int	PmergeMe::strToInt(const std::string& _str) {

	int	_value;
	std::stringstream	strInt(_str);
	strInt >> _value;
	if (strInt.fail())
		throw	ErrorInvalidArgument;
	if (!strInt.eof())
		throw	ErrorInvalidArgument;
	return (_value);
}

bool	PmergeMe::isValidChracters(const std::string& _str) {

	int	countDigit;

	countDigit = 0;
	for (size_t i = 0; i < _str.size(); i++)
	{
		if (!isdigit(_str[i]) && !isPlusOrMinus(_str[i]))
			return (false);
		if (isdigit(_str[i]))
			countDigit++;
	}
	if (countDigit == 0)
		return (false);
	return (true);
}

void	PmergeMe::displayElements(void) {

	std::list<int>::iterator itList = _list.begin();
	// std::vector<int>::iterator itVector = _vector.begin();
	// std::cout << "-------------list--------------" <<  std::endl;
	while (itList != _list.end())
	{
		std::cout << *itList << " " ;
		itList++;
	}
	std::cout << std::endl;
	// std::cout << "-------------vector--------------" <<  std::endl;
	// while (itVector != _vector.end())
	// {
	// 	std::cout << *itVector << " " ;
	// 	itVector++;
	// }
	// std::cout << std::endl;
}

bool	PmergeMe::isAlreadyExist(int _value) {

	std::list<int>::iterator it = _list.begin();
	while (it != _list.end())
	{
		if (*it == _value)
			return (true);
		it++;
	}
	return (false);
}

void	PmergeMe::ParseArgAndStorIt(const std::string& _str) {
	// std::cout << _str << std::endl;
	int	_value;
	if (!isValidChracters(_str))
		throw	ErrorInvalidArgument;
	_value = strToInt(_str);
	if (isAlreadyExist(_value))
		throw	ErrorDuplicateArgument;
	_list.push_back(_value);
	_vector.push_back(_value);
}

void	PmergeMe::mergeSubarrays(std::vector<int>& _vec, int left, int mid, int right) {
	int lenArrayLeft;
	int lenArrayRight;
	int i;
	int j;
	int k;

	lenArrayLeft = mid - left + 1;
	lenArrayRight = right - mid;

	std::vector<int> subArrayLeft(lenArrayLeft), subArrayRight(lenArrayRight);

	i = 0, j = 0;
	for (i < lenArrayLeft; i++)
		subArrayLeft[i] = _vec[lenArrayLeft + i];
	for (j < lenArrayRight; j++)
		subArrayRight[j] = subArrayRight[mid + 1 + j];
	// i = 0
}


void	PmergeMe::MergeSort(std::vector<int>& _vec, int left, int right) {
	int mid;

	if (left >= right)
		return ;
	mid = left + (right - left) / 2;
	MergeSort(_vec, left, mid);
	MergeSort(_vec, mid + 1, right);
	mer
}

const char* PmergeMe::ErrorInvalidArgument::what() const throw() {
	return ("Invalid argument!");
}

const char* PmergeMe::ErrorDuplicateArgument::what() const throw() {
	return ("Duplicate Number!");
}