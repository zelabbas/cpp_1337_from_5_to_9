/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 21:25:39 by zelabbas          #+#    #+#             */
/*   Updated: 2024/08/03 11:23:54 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(void) {
	
}

Serializer::Serializer(const Serializer& _serializer) {
	if (this != &_serializer)
		*this = _serializer;
}

Serializer::~Serializer(void) {
	
}

Serializer& Serializer::operator=(const Serializer& _serializer) {
	if (this != &_serializer)
	{}
	return (*this);
}

uintptr_t	Serializer::serialize(Data *ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Data*	Serializer::deserialize(uintptr_t raw) {
	return reinterpret_cast<Data*>(raw);
}

