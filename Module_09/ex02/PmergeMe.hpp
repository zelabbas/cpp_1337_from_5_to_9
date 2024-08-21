/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 11:20:49 by zelabbas          #+#    #+#             */
/*   Updated: 2024/08/21 14:07:03 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <vector>
#include <deque>
#include <exception>
#include <ctime>
#include <iomanip>
#include <sstream>

class PmergeMe
{
	private:
		int					size;
		std::deque<int>		_deque;
		std::vector<int>	_vector;
		bool				isAlreadyExist(int _number);
		bool				isPlus(char c);
		int					strToInt(const std::string& _str);
		bool				isValidChracters(const std::string& _str);
		void				mergeSubarrays(std::vector<int>& _vec, int left, int mid, int right);
		void				mergeSubarrays(std::deque<int>& _vec, int left, int mid, int right);
		void	StartMergeSortVector(std::vector<int>& _vec, int left, int right);
		void	StartMergeSortDeque(std::deque<int>& _vec, int left, int right);
	public:
		PmergeMe();
		~PmergeMe();
		void	ParseArgAndStorIt(const std::string& _str);
		void	MergeSortVector(void);
		void	MergeSortDeque(void);
		void	displayElements(void);
		int		getSize(void);
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
