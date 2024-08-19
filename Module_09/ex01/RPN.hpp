/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 13:54:16 by zelabbas          #+#    #+#             */
/*   Updated: 2024/08/19 20:37:50 by zelabbas         ###   ########.fr       */
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
		bool				isValidChracters(const std::string& _str);
		bool				isOperator(char c);
		bool				isSpace(char c);
		int					strToInt(const std::string& _str);
		int					whichOperator(const std::string& _str);
		void				operationCalcule(std::string& _piece, std::stack<int>& _stack);
	public:
		RPN();
		~RPN();
		void	parseArg(const std::string& _str);
		void	ReversePolish(std::string& _str); 
		class	ErrorInvalidArgument : public std::exception {
			public :
				const char* what() const throw();
		} ErrorInvalidArgument;
};
