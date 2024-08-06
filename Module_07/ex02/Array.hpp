/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 13:30:23 by zelabbas          #+#    #+#             */
/*   Updated: 2024/08/06 16:40:26 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstddef> 
#include <stdexcept>

template <class T>
class Array
{
	private:
		T* 			_elements;
		std::size_t	_length;
		void	copyElements(const Array& _obj);
	public:
		Array();
		Array(unsigned int _size);
		Array(const Array& _obj);
		~Array();

		Array& operator= (const Array& _obj);
		std::size_t		size(void) const;

		T& operator[](std::size_t index);
		const T& operator[](std::size_t index) const;
};


template <class T>
Array<T>::Array() {
	_elements = NULL;
	_length = 0;
}

template <class T>
void Array<T>::copyElements(const Array& _obj)
{
	if (_elements)
		delete[] _elements;
	_length = _obj._length;
	_elements = new T[_length];
	for (std::size_t i = 0; i < _length; ++i)
	{
		_elements[i] = _obj._elements[i];
	}
}

template <class T>
Array<T>::Array(unsigned int _size) {
	_elements = new T[_size];
	_length = _size;
}

template <class T>
Array<T>::Array(const Array& _obj) {
	_elements = NULL;
	if (this != &_obj)
		copyElements(_obj);
}


template <class T>
Array<T>::~Array()
{
	delete[] _elements;
}

template <class T>
Array<T>& Array<T>::operator=(const Array& _obj)
{
	if (this != &_obj)
		copyElements(_obj);
	return *this;
}

template <class T>
std::size_t Array<T>::size(void) const 
{
	return (_length);
}

template <class T>
T& Array<T>::operator[](std::size_t index) {
	if (index >= _length)
		throw std::out_of_range("index is out of bounds");
	return (_elements[index]);
}

template <class T>
const T& Array<T>::operator[](std::size_t index) const {
	if (index >= _length)
		throw std::out_of_range("index is out of bounds");
	return (_elements[index]);
}