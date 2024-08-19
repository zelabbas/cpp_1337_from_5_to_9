/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 13:54:13 by zelabbas          #+#    #+#             */
/*   Updated: 2024/08/19 21:05:36 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {
	std::cout << "called constructor by default!" << std::endl;
}

RPN::~RPN() {
	std::cout << "destructor called!" << std::endl;
}

bool	RPN::isOperator(char c) {
	return (c == '*' || c == '/' || c == '-' || c == '+');
}

bool	RPN::isSpace(char c) {
	return (c == ' ');
}

bool	RPN::isValidChracters(const std::string& _str) {
	size_t	i;
	static size_t	_countDigit;
	static size_t	_countOperators;

	i = 0;
	while (i < _str.size())
	{
		if (!isdigit((_str[i])) && !isOperator(_str[i])) {
			if (_str[i] != ' ')
				return (false);
			if (isSpace(_str[i]) &&  (i + 1 < _str.size() && isSpace(_str[i + 1])))
				return (false);
		}
		if (isdigit(_str[i])) 
		{
			if (i + 1 < _str.size() && isdigit(_str[i + 1]))
				return false;
			_countDigit++;
		}
		else if (isOperator(_str[i]))
		{
			if ((i + 1 < _str.size() && !isSpace(_str[i + 1])))
				return (false);
			else
			_countOperators++;
		}
		i++;
	}
	if (isSpace(_str[i - 1]) || ((_countDigit - 1) != _countOperators))
		return (false);
	return (true);
}

int	RPN::whichOperator(const std::string& _str) {
	if (_str[0] == '*')
		return (1);
	else if (_str[0] == '/')
		return (2);
	else if (_str[0] == '+')
		return (3);
	else if (_str[0] == '-')
		return (4);
	return (-1);
}

int	RPN::strToInt(const std::string& _str) {
	int					_value;
	std::stringstream	strInt(_str);
	strInt >> _value;
	return (_value);
}

void	RPN::operationCalcule(std::string& _piece, std::stack<int>& _stack) {

	int	firstValue;
	int secondValue;

	if (_stack.size() < 2)
		throw ErrorInvalidArgument;
	firstValue = _stack.top(), _stack.pop();
	secondValue = _stack.top(), _stack.pop();
	switch (whichOperator(_piece))
	{
		case 1:
			_stack.push(firstValue * secondValue);
			break;
		case 2:
			_stack.push(secondValue / firstValue);
			break;
		case 3:
			_stack.push(firstValue + secondValue);
			break;
		case 4:
			_stack.push(secondValue - firstValue);
			break;
		default:
			std::cout << "hello again" << std::endl;
	}
}

void	RPN::ReversePolish(std::string& _str) {
	std::string			_piece;
	std::stringstream	inputString(_str);
	while (getline(inputString, _piece, ' '))
	{
		if (isdigit(_piece[0]))
			_rpnStack.push(strToInt(_piece));
		else
			operationCalcule(_piece, _rpnStack);
	}
	std::cout << "the result is: " << _rpnStack.top() << std::endl;
}

void	RPN::parseArg(const std::string& _str) {
	if (!isdigit(static_cast<int> (_str[0])) || !isValidChracters(_str))
		throw ErrorInvalidArgument;
}

const char* RPN::ErrorInvalidArgument::what() const throw() {
	return ("invalid argument!");
}
