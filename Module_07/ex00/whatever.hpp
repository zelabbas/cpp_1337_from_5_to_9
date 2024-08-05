/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 11:59:34 by zelabbas          #+#    #+#             */
/*   Updated: 2024/08/05 12:15:35 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template <typename T> T min(T a, T b)
{
	return (a < b) ? a : b;
}

template <typename T> T max(T a, T b)
{
	return (a > b) ? a : b;
}

template <typename T> void swap(T &a, T &b)
{
	T c;

	c = a;
	a = b;
	b = c;
}