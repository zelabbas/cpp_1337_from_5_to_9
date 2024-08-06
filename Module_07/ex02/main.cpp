/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 13:30:26 by zelabbas          #+#    #+#             */
/*   Updated: 2024/08/06 19:35:28 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>

int main(int ac, char **av)
{
	(void)av;
	if (ac != 1)
	{
		std::cerr << "Error usage: ./array" << std::endl;
		return (1);
	}
	try
	{
		// Test default constructor
		Array<int> a;
		std::cout << "Size of a: " << a.size() << std::endl;
		const Array<std::string> p(4);
		std::cout << "Size of p: " << p.size() << std::endl;
		for (std::size_t i = 0; i < p.size(); ++i)
		{
			std::cout << "b[" << i << "] = " << p[i] << std::endl;
		}

		// Test constructor with size parameter
		Array<int> b(5);
		std::cout << "Size of b: " << b.size() << std::endl;
		for (std::size_t i = 0; i < b.size(); ++i)
		{
			std::cout << "b[" << i << "] = " << b[i] << std::endl;
		}

		// Test copy constructor
		Array<int> c(b);
		std::cout << "Size of c: " << c.size() << std::endl;
		for (std::size_t i = 0; i < c.size(); ++i)
		{
			std::cout << "c[" << i << "] = " << c[i] << std::endl;
		}
	
		// Modify original array and check if copy is unaffected
		b[0] = 42;
		std::cout << "After modifying b[0], b[0] = " << b[0] << ", c[0] = " << c[0] << std::endl;

		// Test assignment operator
		Array<int> d;
		d = b;
		std::cout << "Size of d: " << d.size() << std::endl;
		for (std::size_t i = 0; i < d.size(); ++i)
		{
			std::cout << "d[" << i << "] = " << d[i] << std::endl;
		}

		// Modify original array and check if copy is unaffected
		b[1] = 99;
		std::cout << "After modifying b[1], b[1] = " << b[1] << ", d[1] = " << d[1] << std::endl;

		// Test out of bounds access
		std::cout << "Accessing b[5]: " << b[5] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}

