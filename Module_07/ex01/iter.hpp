/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 12:23:58 by zelabbas          #+#    #+#             */
/*   Updated: 2024/08/06 18:50:00 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once 
#include <cstddef>
#include <stdexcept> 

template <typename T, typename F> 
void iter(T* a, std::size_t length , void (*fun)(F&))
{
	if (!a || !fun)
		throw std::invalid_argument("Null pointer exception");
	for (size_t i = 0; i < length; i++)
		fun(a[i]);
}