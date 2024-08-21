/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 11:20:51 by zelabbas          #+#    #+#             */
/*   Updated: 2024/08/21 14:11:40 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {
	std::cout << "constructor by default called" << std::endl;
	size = 0;
}

PmergeMe::~PmergeMe() {
	std::cout << "Destructor called" << std::endl; 
}

bool	PmergeMe::isPlus(char c) {
	return (c == '+');
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
		if (!isdigit(_str[i]) && !isPlus(_str[i]))
			return (false);
		if (isdigit(_str[i]))
			countDigit++;
	}
	if (countDigit == 0)
		return (false);
	return (true);
}

void	PmergeMe::displayElements(void) {

	std::deque<int>::iterator itDeque = _deque.begin();
	std::cout << "-------------deque--------------" <<  std::endl;
	while (itDeque != _deque.end())
	{
		std::cout << *itDeque << " " ;
		itDeque++;
	}
	std::cout << std::endl;
	// std::cout << "-------------vector--------------" <<  std::endl;
	// std::vector<int>::iterator itVector = _vector.begin();
	// while (itVector != _vector.end())
	// {
	// 	std::cout << *itVector << " " ;
	// 	itVector++;
	// }
	// std::cout << std::endl;
}

bool	PmergeMe::isAlreadyExist(int _value) {

	std::deque<int>::iterator it = _deque.begin();
	while (it != _deque.end())
	{
		if (*it == _value)
			return (true);
		it++;
	}
	return (false);
}

void	PmergeMe::ParseArgAndStorIt(const std::string& _str) {
	int	_value;
	if (!isValidChracters(_str))
		throw	ErrorInvalidArgument;
	_value = strToInt(_str);
	if (isAlreadyExist(_value))
		throw	ErrorDuplicateArgument;
	_deque.push_back(_value);
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
	while (i < lenArrayLeft) {
		subArrayLeft[i] = _vec[left + i];
		i++;
	}
	while (j < lenArrayRight) {
		subArrayRight[j] = _vec[mid + 1 + j];
		j++;
	}
	i = 0, j = 0;
	k = left;
	while (i < lenArrayLeft && j < lenArrayRight)
	{
		if (subArrayLeft[i] <= subArrayRight[j])
		{
			_vec[k] = subArrayLeft[i];
			i++;
		}
		else
		{
			_vec[k] = subArrayRight[j];
			j++;
		}
		k++;
	}
	while (i < lenArrayLeft) 
	{
		_vec[k] = subArrayLeft[i];
		i++;
		k++;
	}
	while (j < lenArrayRight) 
	{
		_vec[k] = subArrayRight[j];
		j++;
		k++;
	}
}

void	PmergeMe::mergeSubarrays(std::deque<int>& _vec, int left, int mid, int right) {
	int lenArrayLeft;
	int lenArrayRight;
	int i;
	int j;
	int k;

	lenArrayLeft = mid - left + 1;
	lenArrayRight = right - mid;

	std::deque<int> subArrayLeft(lenArrayLeft), subArrayRight(lenArrayRight);

	i = 0, j = 0;
	while (i < lenArrayLeft) {
		subArrayLeft[i] = _vec[left + i];
		i++;
	}
	while (j < lenArrayRight) {
		subArrayRight[j] = _vec[mid + 1 + j];
		j++;
	}
	i = 0, j = 0;
	k = left;
	while (i < lenArrayLeft && j < lenArrayRight)
	{
		if (subArrayLeft[i] <= subArrayRight[j])
		{
			_vec[k] = subArrayLeft[i];
			i++;
		}
		else
		{
			_vec[k] = subArrayRight[j];
			j++;
		}
		k++;
	}
	while (i < lenArrayLeft) 
	{
		_vec[k] = subArrayLeft[i];
		i++;
		k++;
	}
	while (j < lenArrayRight) 
	{
		_vec[k] = subArrayRight[j];
		j++;
		k++;
	}
}


void	PmergeMe::StartMergeSortVector(std::vector<int>& _vec, int left, int right) {
	int mid;

	if (left >= right)
		return ;
	mid = left + (right - left) / 2;
	StartMergeSortVector(_vec, left, mid);
	StartMergeSortVector(_vec, mid + 1, right);
	mergeSubarrays(_vec, left, mid, right);
}


void	PmergeMe::StartMergeSortDeque(std::deque<int>& _deque, int left, int right) {
	int mid;

	if (left >= right)
		return ;
	mid = left + (right - left) / 2;
	StartMergeSortDeque(_deque, left, mid);
	StartMergeSortDeque(_deque, mid + 1, right);
	mergeSubarrays(_deque, left, mid, right);
}


void	PmergeMe::MergeSortVector(void) {
	size = _vector.size();
	StartMergeSortVector(_vector, 0, _vector.size() - 1);
}

void	PmergeMe::MergeSortDeque(void) {
	size = _deque.size();
	StartMergeSortDeque(_deque, 0, _deque.size() - 1);
}

int	PmergeMe::getSize(void) {
	return (size);
}

const char* PmergeMe::ErrorInvalidArgument::what() const throw() {
	return ("Invalid argument!");
}

const char* PmergeMe::ErrorDuplicateArgument::what() const throw() {
	return ("Duplicate Number!");
}