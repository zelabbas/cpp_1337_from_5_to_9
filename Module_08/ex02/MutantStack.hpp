/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 15:19:30 by zelabbas          #+#    #+#             */
/*   Updated: 2024/08/11 16:26:52 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	private:
		/* data */
	public:
		typedef typename std::deque<T>::iterator iterator;
		MutantStack();
		MutantStack(const MutantStack& _stack);
		~MutantStack();

		MutantStack& operator= (const MutantStack& _stack);

		iterator begin();
		iterator end();
	
};

template <typename T>
MutantStack<T>::MutantStack() : std::stack<T> (){
	std::cout << "constructor called" << std::endl;
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack& _stack) : std::stack<T>(_stack) {
	if (this != &_stack)
		*this = _stack;
}

template <typename T>
MutantStack<T>::~MutantStack() {
	std::cout << "Desstructor called" << std::endl;
}


template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack& _stack) {
	if (this != &_stack)
	{
		std::stack<T>::operator=(_stack);
	}
	return *this;
}

template <typename T>
typename std::deque<T>::iterator MutantStack<T>::begin() {
	return this->c.begin();
}

template <typename T>
typename std::deque<T>::iterator MutantStack<T>::end() {
	return this->c.end();
}