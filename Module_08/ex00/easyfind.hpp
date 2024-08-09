/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 12:07:50 by zelabbas          #+#    #+#             */
/*   Updated: 2024/08/09 09:49:18 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template <typename T>
typename T::iterator easyfind(T& container, int value)
{
	typename T::iterator it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
	{
		throw std::runtime_error("Value not found in the container");
	}
	return it;
}