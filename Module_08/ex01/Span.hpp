/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 10:34:32 by zelabbas          #+#    #+#             */
/*   Updated: 2024/08/09 14:54:50 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <cstddef>
#include <algorithm>
#include <stdexcept>
#include <iostream>

template <class T>
class Span {

	private:
		T*			_arrayElements;
		std::size_t	_size;
		std::size_t	_index;
		void		copyElements(const Span& _obj);
	public:
		Span();
		Span(unsigned int _N);
		Span(const Span& _obj);
		~Span();

		Span& operator=(const Span& _obj);
		void	addNumber(int _number);
		T		shortestSpan();
		T		longestSpan();
		void	FillArray();
};

// constructor by default
template <class T>
Span<T>::Span() {

	_arrayElements = NULL;
	_size = 0;
	_index = 0;
}

// constructor by parameters
template <class T>
Span<T>::Span(unsigned int _N) {

	_arrayElements = new T[_N];
	_size = _N;
	_index = 0;
}

// destructor 
template <class T>
Span<T>::~Span() {

	delete[] _arrayElements;
}


// copy elements from an array to another array
template <class T>
void Span<T>::copyElements(const Span& _obj) {

	if (_arrayElements)
		delete[] _arrayElements;
	_size = _obj._size;
	_index = _obj._index;
	_arrayElements = new T[_size];
	for (std::size_t i = 0; i < _size; ++i)
	{
		_arrayElements[i] = _obj._arrayElements[i];
	}
}

// constructor by copy
template <class T>
Span<T>::Span(const Span& _obj) {

	_arrayElements = NULL;
	if (this != &_obj)
		copyElements(_obj);
}

// assignement operator 
template <class T>
Span<T>& Span<T>::operator=(const Span& _obj) {

	if (this != &_obj)
		copyElements(_obj);
	return (*this);
}

// add an element to the _arrayElements
template <class T>
void	Span<T>::addNumber(int _number)
{
	if (_index >= _size)
		throw	std::out_of_range("ops >>> the array is full!");
	_arrayElements[_index++] = _number;
}

// find the longest distance 
template <class T>
T	Span<T>::longestSpan() {
	
	if (_index < 2)
		throw std::invalid_argument("Not enough elements to find a span");
	std::sort(_arrayElements, _arrayElements + _index);
	return (_arrayElements[_index - 1] - _arrayElements[0]);
}

// find the shortest distance
template <class T>
T Span<T>::shortestSpan() {

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
template <class T>
void	Span<T>::FillArray() {

	std::srand(time(NULL));
	for (size_t i = 0; i < _size; i++)
	{
		int n = std::rand();
		std::cout << n << std::endl;
		_arrayElements[i] = n;
	}
	_index = _size;
}