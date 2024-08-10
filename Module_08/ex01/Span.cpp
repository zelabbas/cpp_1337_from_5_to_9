/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 10:31:29 by zelabbas          #+#    #+#             */
/*   Updated: 2024/08/10 14:39:32 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

// constructor by default
Span::Span() {

	_arrayElements = NULL;
	_size = 0;
	_index = 0;
}

// constructor by parameters
Span::Span(unsigned int _N) {

	_arrayElements = new int[_N];
	_size = _N;
	_index = 0;
}

// destructor 
Span::~Span() {

	delete[] _arrayElements;
}


// copy elements from an array to another array
void Span::copyElements(const Span& _obj) {

	if (_arrayElements)
		delete[] _arrayElements;
	_size = _obj._size;
	_index = _obj._index;
	_arrayElements = new int[_size];
	for (std::size_t i = 0; i < _size; ++i)
	{
		_arrayElements[i] = _obj._arrayElements[i];
	}
}

// constructor by copy
Span::Span(const Span& _obj) {

	_arrayElements = NULL;
	if (this != &_obj)
		copyElements(_obj);
}

// assignement operator 
Span& Span::operator=(const Span& _obj) {

	if (this != &_obj)
		copyElements(_obj);
	return (*this);
}

// add an element to the _arrayElements
void	Span::addNumber(int _number)
{
	if (_index >= _size)
		throw	std::out_of_range("ops >>> the array is full!");
	_arrayElements[_index++] = _number;
}

// find the longest distance 
int	Span::longestSpan() {
	
	if (_index < 2)
		throw std::invalid_argument("Not enough elements to find a span");
	std::sort(_arrayElements, _arrayElements + _index);
	return (_arrayElements[_index - 1] - _arrayElements[0]);
}

// find the shortest distance
int Span::shortestSpan() {

	int _Distance;
	if (_index < 2)
		throw std::invalid_argument("Not enough elements to find a span");
	std::sort(_arrayElements, _arrayElements + _index);
	_Distance = _arrayElements[1] - _arrayElements[0];
	for (size_t i = 1; i < _index - 1; i++)
	{
		if (_Distance > (_arrayElements[i + 1] - _arrayElements[i]))
			_Distance = _arrayElements[i + 1] - _arrayElements[i];
	}
	return (_Distance);
}

// fill all elements in the array once
void	Span::FillArray() {

	std::srand(time(NULL));
	for (size_t i = 0; i < _size; i++)
	{
		int n = std::rand();
		std::cout << n << std::endl;
		_arrayElements[i] = n;
	}
	_index = _size;
}