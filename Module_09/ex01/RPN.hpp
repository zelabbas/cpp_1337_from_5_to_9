/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 13:54:16 by zelabbas          #+#    #+#             */
/*   Updated: 2024/08/19 22:14:17 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <exception>
#include <stack>
#include <sstream>

class RPN
{
	private:
		/* data */
		std::stack<int>		_rpnStack;
		bool				isValidChracters(const std::string& _str) const;
		bool				isOperator(char c) const;
		bool				isSpace(char c) const;
		int					strToInt(const std::string& _str) const;
		int					whichOperator(const std::string& _str) const;
		void				isOperationValid(int firstValue, int secondValue, char _operator) const;
		void				operationCalcule(std::string& _piece, std::stack<int>& _stack);
	public:
		RPN();
		RPN(const RPN& _rpn);
		~RPN();
		RPN& operator=(const RPN& _rpn);
		void	parseArg(const std::string& _str) const;
		void	ReversePolish(std::string& _str); 
		class	ErrorInvalidArgument : public std::exception {
			public :
				const char* what() const throw();
		} ErrorInvalidArgument;

		class	ErrorOverFlow : public std::exception {
			public :
				const char* what() const throw();
		} ErrorOverFlow;
};
