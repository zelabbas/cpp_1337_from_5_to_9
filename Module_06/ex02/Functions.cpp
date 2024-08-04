/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Functions.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 15:41:58 by zelabbas          #+#    #+#             */
/*   Updated: 2024/08/04 21:56:36 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Functions.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <ctime>

Base*	generate(void) {
	std::srand(std::time(NULL));

	switch (std::rand() % 3)
	{
		case 0:
			return new A();
		case 1:
			return new B();
		case 2:
			return new C();
		default:
			return (NULL);
	}
}

void	identify(Base* p) {
	if (dynamic_cast<A*> (p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*> (p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*> (p))
		std::cout << "C" << std::endl;
}

void	identify(Base& p) {
	
	try
	{
		(void)dynamic_cast<A&> (p);
		std::cout << "A" << std::endl;
	}
	catch(std::bad_cast& b) {}

	try
	{
		(void)dynamic_cast<B&> (p);
		std::cout << "B" << std::endl;
	}
	catch(std::bad_cast& b) {}

	try
	{
		(void)dynamic_cast<C&> (p);
		std::cout << "C" << std::endl;
	}
	catch(std::bad_cast& b) {}
}
