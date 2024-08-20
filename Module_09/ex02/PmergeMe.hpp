/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 11:20:49 by zelabbas          #+#    #+#             */
/*   Updated: 2024/08/20 16:40:51 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <exception>
#include <sstream>

class PmergeMe
{
	private:
		std::list<int>		_list;
		std::vector<int>	_vector;
		bool				isAlreadyExist(int _number);
		bool				isPlusOrMinus(char c);
		int					strToInt(const std::string& _str);
		bool				isValidChracters(const std::string& _str);
		void				mergeSubarrays(std::vector<int>& _vec, int left, int mid, int right);
	public:
		PmergeMe();
		~PmergeMe();
		void	ParseArgAndStorIt(const std::string& _str);
		void	MergeSort(std::vector<int>& _vec, int left, int right);
		void	displayElements(void);
		class ErrorInvalidArgument : public std::exception
		{
			public:
				const char* what() const throw();
		}	ErrorInvalidArgument;
		class ErrorDuplicateArgument : public std::exception
		{
			public:
				const char* what() const throw();
		}	ErrorDuplicateArgument;
};
