/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 21:25:37 by zelabbas          #+#    #+#             */
/*   Updated: 2024/08/02 22:00:39 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

typedef	struct s_data {
	int		intValue;
	float	floatValue;
	char	charValue;
	bool	boolValue;	
}	Data;

class Serializer
{
	private:
		Serializer(void);
		Serializer(const Serializer& );
		Serializer& operator= (const Serializer& );
		~Serializer(void);

	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};
