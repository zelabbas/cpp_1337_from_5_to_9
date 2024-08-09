/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 10:31:29 by zelabbas          #+#    #+#             */
/*   Updated: 2024/08/09 11:52:14 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

// // constructor by default
// template <class T>
// Span<T>::Span() {

// 	_arrayElements = NULL;
// 	_size = 0;
// 	_index = 0;
// }

// // constructor by parameters
// template <class T>
// Span<T>::Span(unsigned int _N) {

// 	_arrayElements = new T[_N];
// 	_size = _N;
// 	_index = 0;
// }

// // destructor 
// template <class T>
// Span<T>::~Span() {

// 	delete[] _arrayElements;
// }


// // copy elements from an array to another array
// template <class T>
// void Span<T>::copyElements(const Span& _obj) {

// 	if (_arrayElements)
// 		delete[] _arrayElements;
// 	_size = _obj._size;
// 	_index = _obj._index;
// 	_arrayElements = new T[_size];
// 	for (std::size_t i = 0; i < _size; ++i)
// 	{
// 		_arrayElements[i] = _obj._arrayElements[i];
// 	}
// }

// // constructor by copy
// template <class T>
// Span<T>::Span(const Span& _obj) {

// 	_arrayElements = NULL;
// 	if (this != &_obj)
// 		copyElements(_obj);
// }

// // assignement operator 
// template <class T>
// Span<T>& Span<T>::operator=(const Span& _obj) {

// 	if (this != &_obj)
// 		copyElements(_obj);
// 	return (*this);
// }

// // add an element to the _arrayElements
// template <class T>
// void	Span<T>::addNumber(int _number)
// {
// 	if (_index >= _size)
// 		throw	std::out_of_range("ops >>> the array is full!");
// 	_arrayElements[_index++] = _number;
// }