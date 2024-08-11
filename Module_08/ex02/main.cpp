/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 15:19:33 by zelabbas          #+#    #+#             */
/*   Updated: 2024/08/11 16:26:09 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>

int main(int ac, char **av)
{
	(void)av;
	if (ac != 1)
	{
		std::cerr << "Error usage: ./mutantstack" << std::endl;
		return (1);
	}
	MutantStack<std::string> mstack;
	mstack.push("5");
	mstack.push("17");
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push("3");
	mstack.push("5");
	mstack.push("737");
	mstack.push("0");
	MutantStack<std::string>::iterator it = mstack.begin();
	MutantStack<std::string>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	std::stack<std::string> s(mstack);
	return (0);
}