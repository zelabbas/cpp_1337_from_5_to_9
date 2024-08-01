/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 16:18:32 by zelabbas          #+#    #+#             */
/*   Updated: 2024/08/01 17:06:53 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <iomanip>

typedef enum s_type{
	_CHAR,
	_INT,
	_FLOAT,
	_DOUBLE,
	_MINUSINF,
	_PLUSINF,
	_NANF,
	_STRING
}	t_type;

class ScalarConverter
{
	private:
		static int	getType(const std::string &str);
		static int	detectType(const std::string &str);
		static int	AnoramlType(const std::string &str);
		static void	charCase(const std::string& str);
		static void	minusInfAndMinusInffCase(void);
		static void	plusInfAndPlusInffCase(void);
		static void	nanAndNanfCase(void);
		static void	stringCase(void);
		ScalarConverter();
		ScalarConverter(const ScalarConverter& );
	public:
		~ScalarConverter();

		ScalarConverter& operator= (const ScalarConverter& );

		static void convert(const std::string& );
};
