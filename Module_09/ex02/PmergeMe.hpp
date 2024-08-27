/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 11:20:49 by zelabbas          #+#    #+#             */
/*   Updated: 2024/08/27 20:51:26 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <vector>
#include <deque>
#include <exception>
#include <sys/time.h>
#include <iomanip>
#include <utility>
#include <sstream>

class PmergeMe
{
	private:
		int					size;
		int					lastElement;
		std::deque<int>		_deque;
		std::vector<int>	_vector;
		bool				isAlreadyExist(int _number);
		bool				isPlus(char c);
		int					strToInt(const std::string& _str);
		bool				isValidChracters(const std::string& _str);
		// vector
		void				makePairsVector(std::vector<std::pair<int , int> >& _pairVector);
		void				mainPendChainVector(std::vector<int>& _mainVect, std::vector<int>& _tmpVect,std::vector<std::pair<int , int> >& _pairVector);
		void				sortEachPairVector(std::vector<std::pair<int , int> >& _pairVector);
		void				mergeMainPendChainVector(std::vector<int>& _mainVect, std::vector<int>& _tmpVect);
		void				copyMainChaintoMainVector(std::vector<int>& _mainVect);
		// deque
		void				makePairsDeque(std::deque<std::pair<int , int> >& _pairVector);
		void				mainPendChainDeque(std::deque<int>& _mainVect, std::deque<int>& _tmpVect,std::deque<std::pair<int , int> >& _pairVector);
		void				sortEachPairDeque(std::deque<std::pair<int , int> >& _pairVector);
		void				mergeMainPendChainDeque(std::deque<int>& _mainVect, std::deque<int>& _tmpVect);
		void				copyMainChaintoMainDeque(std::deque<int>& _mainVect);
		// void				mergeSubarrays(std::vector<int>& _vec, int left, int mid, int right);
		// void				mergeSubarrays(std::deque<int>& _vec, int left, int mid, int right);
		// void	StartMergeSortVector(std::vector<int>& _vec, int left, int right);
		// void	StartMergeSortDeque(std::deque<int>& _vec, int left, int right);
	public:
		PmergeMe();
		PmergeMe(const PmergeMe& _pmrge);
		~PmergeMe();
	
		PmergeMe& operator=(const PmergeMe& _pmrge);
		void	ParseArgAndStorIt(const std::string& _str);
		void	FordJohnsonVector(void);
		void	FordJohnsonDeque(void);
		void	displayElementsVector(void);
		void	displayElementsDeque(void);
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

