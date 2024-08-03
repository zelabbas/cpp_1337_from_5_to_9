/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 16:03:22 by zelabbas          #+#    #+#             */
/*   Updated: 2024/08/03 16:46:08 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Functions.hpp"

int main(int ac, char **av)
{
	(void)av;
	Base* poly;

	if (ac != 1)
	{
		std::cerr << "Error usage: ./real_type" << std::endl;
		return (1);
	}
	poly = generate();
	if (!poly)
	{
		std::cerr << "Error : failde to allocate memory! or type unknown!" << std::endl;
		return (1);
	}

	// Identify the type using a pointer
	identify(poly);

	// Identify the type using a reference
	identify(*poly);
	delete poly;
	return (0);
}
