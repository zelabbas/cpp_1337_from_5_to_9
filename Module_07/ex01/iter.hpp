/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 12:23:58 by zelabbas          #+#    #+#             */
/*   Updated: 2024/08/05 12:46:16 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once 
#include <cstddef>
template <typename T> void swap(T &a, T &b)
{
	T c;

	c = a;
	a = b;
	b = c;
}


template <typename T, typename Func> void iter(T* a, size_t length , Func fun)
{
	for (size_t i = 0; i < length - 1; i++)
		for (size_t j = length - 1; i < j; j--)
			if (a[j] < a[j - 1])
				fun(a[j], a[j - 1]);
}