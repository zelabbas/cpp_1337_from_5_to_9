/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 11:20:51 by zelabbas          #+#    #+#             */
/*   Updated: 2024/09/05 16:15:23 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {
	std::cout << "constructor by default called" << std::endl;
	size = 0;
}

PmergeMe::PmergeMe(const PmergeMe& _pmrge) {
	if (this != &_pmrge)
		*this = _pmrge;
}

PmergeMe::~PmergeMe() {
	std::cout << "Destructor called" << std::endl; 
}

PmergeMe&	PmergeMe::operator=(const PmergeMe& _pmrge) {
	if (this != &_pmrge) {
		_deque = _pmrge._deque;
		_vector = _pmrge._vector;
		size = _pmrge.size;
		lastElement = _pmrge.lastElement;
	}
	return (*this);
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
	size_t	i = 0;
	while (i < _str.size())
	{
		if (isspace(_str[i]))
			i++;
		else
			break;
	}
	while (i < _str.size())
	{
		if (!isdigit(_str[i]) && !isPlus(_str[i]))
			return (false);
		if (isdigit(_str[i]))
			countDigit++;
		i++;
	}
	if (countDigit == 0)
		return (false);
	return (true);
}

void	PmergeMe::displayElementsDeque(void) {

	std::deque<int>::iterator itDeque = _deque.begin();
	std::cout << "-------------deque--------------" <<  std::endl;
	while (itDeque != _deque.end())
	{
		std::cout << *itDeque << " " ;
		itDeque++;
	}
	std::cout << std::endl;
}

void	PmergeMe::displayElementsVector(void) {
	std::cout << "-------------vector--------------" <<  std::endl;
	std::vector<int>::iterator itVector = _vector.begin();
	while (itVector != _vector.end())
	{
		std::cout << *itVector << " " ;
		itVector++;
	}
	std::cout << std::endl;
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
	// if (isAlreadyExist(_value))
	// 	throw	ErrorDuplicateArgument;
	_deque.push_back(_value);
	_vector.push_back(_value);
}

// start vector sort
void	PmergeMe::makePairsVector(std::vector<std::pair<int , int> >& _pairVector) {

	std::vector<int>::iterator	it;
	it = _vector.begin();
	while (it != _vector.end())
	{
		_pairVector.insert(_pairVector.end(), std::make_pair(*it, *(it + 1)));
		it +=2;
	}
}

void	PmergeMe::mainPendChainVector(std::vector<int>& _mainVect, std::vector<int>& _tmpVect,std::vector<std::pair<int , int> >& _pairVector) {
	std::vector<std::pair<int, int> >::iterator	it;

	it = _pairVector.begin();
	if (it != _pairVector.end())
	{
		_mainVect.push_back(it->second);
		_mainVect.push_back(it->first);
		it++;
	}
	while (it != _pairVector.end())
	{
		_mainVect.push_back(it->first);
		_tmpVect.push_back(it->second);
		it++;
	}
}

void	PmergeMe::sortEachPairVector(std::vector<std::pair<int , int> >& _pairVector) {
	std::vector<std::pair<int , int> >::iterator	it;

	it = _pairVector.begin();
	while (it != _pairVector.end())
	{
		if (it->first < it->second) {
			it->first ^= it->second;
			it->second ^= it->first;
			it->first ^= it->second;
		}
		it++;
	}
}

void	PmergeMe::mergeMainPendChainVector(std::vector<int>& _mainVect, std::vector<int>& _tmpVect) {

	std::vector<int>::iterator	itMain;
	std::vector<int>::iterator	itPend;

	itPend = _tmpVect.begin();
	while (itPend != _tmpVect.end()) {
		itMain = std::upper_bound(_mainVect.begin(), _mainVect.end(), *itPend);
		_mainVect.insert(itMain, *itPend);
		itPend++;
	}
}

void	PmergeMe::copyMainChaintoMainVector(std::vector<int>& _mainVect) {
	std::vector<int>::iterator	it;
	std::vector<int>::iterator	posLastElement;

	_vector.clear();
	it = _mainVect.begin();
	while (it != _mainVect.end())
	{
		_vector.push_back(*it);
		it++;
	}
	if (lastElement != -1)
	{
		posLastElement = std::upper_bound(_vector.begin(), _vector.end(), lastElement);
		_vector.insert(posLastElement, lastElement);
	}
}

void	PmergeMe::FordJohnsonVector(void) {
	size = _vector.size();
	std::vector<std::pair<int, int> > _pairVector;
	std::vector<int> mainVector;
	std::vector<int> tmpVector;

	lastElement = -1;
	if (_vector.size() % 2) {
		lastElement = *(--(_vector.end()));
		_vector.pop_back();
	}
	makePairsVector(_pairVector);
	sortEachPairVector(_pairVector);
	std::sort(_pairVector.begin(), _pairVector.end());
	mainPendChainVector(mainVector, tmpVector, _pairVector);
	mergeMainPendChainVector(mainVector, tmpVector);
	copyMainChaintoMainVector(mainVector);
	_pairVector.clear();
	mainVector.clear();
	tmpVector.clear();
}
// end vector sort 

/////////////////////////////////////////////////////////////////////////////////////////

// start deque sort 
void	PmergeMe::makePairsDeque(std::deque<std::pair<int , int> >& _pairDeque) {

	std::deque<int>::iterator	it;
	it = _deque.begin();
	while (it != _deque.end())
	{
		_pairDeque.insert(_pairDeque.end(), std::make_pair(*it, *(it + 1)));
		it += 2;
	}
}

void	PmergeMe::mainPendChainDeque(std::deque<int>& _mainDeque, std::deque<int>& _tmpDeque,std::deque<std::pair<int , int> >& _pairDeque) {
	std::deque<std::pair<int, int> >::iterator	it;

	it = _pairDeque.begin();
	if (it != _pairDeque.end())
	{
		_mainDeque.push_back(it->second);
		_mainDeque.push_back(it->first);
		it++;
	}
	while (it != _pairDeque.end())
	{
		_mainDeque.push_back(it->first);
		_tmpDeque.push_back(it->second);
		it++;
	}
}

void	PmergeMe::sortEachPairDeque(std::deque<std::pair<int , int> >& _pairDeque) {
	std::deque<std::pair<int , int> >::iterator	it;

	it = _pairDeque.begin();
	while (it != _pairDeque.end())
	{
		if (it->first < it->second) {
			it->first ^= it->second;
			it->second ^= it->first;
			it->first ^= it->second;
		}
		it++;
	}
}

void	PmergeMe::mergeMainPendChainDeque(std::deque<int>& _mainDeque, std::deque<int>& _tmpDeque) {

	std::deque<int>::iterator	itMain;
	std::deque<int>::iterator	itPend;

	itPend = _tmpDeque.begin();
	while (itPend != _tmpDeque.end()) {
		itMain = std::upper_bound(_mainDeque.begin(), _mainDeque.end(), *itPend);
		_mainDeque.insert(itMain, *itPend);
		itPend++;
	}
}

void	PmergeMe::copyMainChaintoMainDeque(std::deque<int>& _mainDeque) {
	std::deque<int>::iterator	it;
	std::deque<int>::iterator	posLastElement;

	_deque.clear();
	it = _mainDeque.begin();
	while (it != _mainDeque.end())
	{
		_deque.push_back(*it);
		it++;
	}
	if (lastElement != -1)
	{
		posLastElement = std::upper_bound(_deque.begin(), _deque.end(), lastElement);
		_deque.insert(posLastElement, lastElement);
	}
}

void	PmergeMe::FordJohnsonDeque(void) {
	size = _deque.size();
	std::deque<std::pair<int, int> > _pairDeque;
	std::deque<int> mainDeque;
	std::deque<int> tmpDeque;

	lastElement = -1;
	if (_deque.size() % 2) {
		lastElement = *(--(_deque.end()));
		_deque.pop_back();
	}
	makePairsDeque(_pairDeque);
	sortEachPairDeque(_pairDeque);
	std::sort(_pairDeque.begin(), _pairDeque.end());
	mainPendChainDeque(mainDeque, tmpDeque, _pairDeque);
	mergeMainPendChainDeque(mainDeque, tmpDeque);
	copyMainChaintoMainDeque(mainDeque);
	_pairDeque.clear();
	mainDeque.clear();
	tmpDeque.clear();
}
// end deque sort

int	PmergeMe::getSize(void) {
	return (size);
}

const char* PmergeMe::ErrorInvalidArgument::what() const throw() {
	return ("Invalid argument!");
}

const char* PmergeMe::ErrorDuplicateArgument::what() const throw() {
	return ("Duplicate Number!");
}