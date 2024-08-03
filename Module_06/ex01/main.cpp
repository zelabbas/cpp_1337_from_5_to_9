/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 21:40:00 by zelabbas          #+#    #+#             */
/*   Updated: 2024/08/03 11:25:36 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(int ac, char **av)
{
	(void)av;
	Data originalData;
	uintptr_t serialized;
	Data* deserializedData;
	if (ac != 1)
	{
		std::cerr << "Error usage: ./serializer" << std::endl;
		return (1);
	}
	originalData.boolValue = true;
	originalData.charValue = 'c';
	originalData.floatValue = 10.56f;
	originalData.intValue = 78;
	serialized = Serializer::serialize(&originalData);
	deserializedData = Serializer::deserialize(serialized);
	if (deserializedData == &originalData)
	{
		std::cout << "Serialization and deserialization successful!" << std::endl;
		std::cout << "intValue: " << deserializedData->intValue << std::endl;
		std::cout << "floatValue: " << deserializedData->floatValue << std::endl;
		std::cout << "charValue: " << deserializedData->charValue << std::endl;
		std::cout << "charValue: " << deserializedData->boolValue << std::endl;
	}
	else
		std::cout << "Serialization and deserialization failed!" << std::endl;
	return (0);
}

