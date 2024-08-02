/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 16:24:22 by zelabbas          #+#    #+#             */
/*   Updated: 2024/08/02 21:05:00 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
	(void)av;

	if (ac != 2)
	{
		std::cerr << "Error usage: ./scalar arg" << std::endl;
		return (1);
	}
	ScalarConverter::convert(static_cast<std::string>(av[1]));
	return (0);
}