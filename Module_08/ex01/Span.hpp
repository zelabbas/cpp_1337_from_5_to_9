/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 10:34:32 by zelabbas          #+#    #+#             */
/*   Updated: 2024/08/10 14:40:48 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <cstddef>
#include <algorithm>
#include <stdexcept>
#include <iostream>

class Span {

	private:
		int*			_arrayElements;
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
		int		shortestSpan();
		int		longestSpan();
		void	FillArray();
};