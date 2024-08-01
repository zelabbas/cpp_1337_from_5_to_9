/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 16:18:29 by zelabbas          #+#    #+#             */
/*   Updated: 2024/08/01 22:17:43 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){
	
}

ScalarConverter::ScalarConverter(const ScalarConverter& _scalar){
	if (this != &_scalar)
		*this = _scalar;
}

ScalarConverter::~ScalarConverter(){
	
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& _scalar){
	if (this != &_scalar)
	{
		
	}
	return (*this);
}

int	ScalarConverter::detectType(const std::string &str)
{
	int i;

	i = 0;
	if (str.size() == 0 || (str.size() == 1 && str[1] == '\0'))
		return (_CHAR);
	i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (isdigit(str[i]))
		i++;
	if (str[i] == '\0')
		return (_INT);
	else if (str[i] == '.')
	{
		i++;
		while (isdigit(str[i]))
			i++;
		if (str[i] == 'f' && str[i + 1] == '\0')
			return (_FLOAT);
		else
		{
			if (str[i] == '\0')
				return (_DOUBLE);
		}
	}
	return (_STRING);
}

int ScalarConverter::AnoramlType(const std::string& str)
{
	if (!str.compare("-inff") || !str.compare("-inf"))
		return (_MINUSINF);
	if (!str.compare("+inff") || !str.compare("+inf"))
		return (_PLUSINF);
	if (!str.compare("nanf") || !str.compare("nan"))
		return (_NANF);
	return (_STRING);
}

int	ScalarConverter::getType(const std::string& str)
{
	int	_type;

	_type = detectType(str);
	if (_type != _STRING)
		return (_type);
	return (AnoramlType(str));
}

void	ScalarConverter::charCase(const std::string& str)
{
	char _char;

	_char = static_cast<char>(str[0]);
	if (isprint(_char))
		std::cout << "char: '" << _char << "'" << std::endl;
	else
		std::cout << "char: " << "Non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(_char) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(_char) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(_char) << std::endl;
}

void	ScalarConverter::stringCase(void)
{
	std::cout << "char: " << "converter Impossible" << std::endl;
	std::cout << "int: " << "converter Impossible" << std::endl;
	std::cout << "float: " << "converter Impossible" << std::endl;
	std::cout << "double: " << "converter Impossible" << std::endl;
}

void	ScalarConverter::minusInfAndMinusInffCase(void)
{
	std::cout << "char: " << "converter Impossible" << std::endl;
	std::cout << "int: " << "converter Impossible" << std::endl;
	std::cout << "float: " << "-inff" << std::endl;
	std::cout << "double: " << "-inf" << std::endl;
}

void	ScalarConverter::plusInfAndPlusInffCase(void)
{
	std::cout << "char: " << "converter Impossible" << std::endl;
	std::cout << "int: " << "converter Impossible" << std::endl;
	std::cout << "float: " << "+inff" << std::endl;
	std::cout << "double: " << "+inf" << std::endl;
}

void	ScalarConverter::nanAndNanfCase(void)
{
	std::cout << "char: " << "converter Impossible" << std::endl;
	std::cout << "int: " << "converter Impossible" << std::endl;
	std::cout << "float: " << "nanf" << std::endl;
	std::cout << "double: " << "nan" << std::endl;
}

void	ScalarConverter::convert(const std::string& str) {
	
	int _type;

	_type = getType(str);
	switch (_type)
	{
		case _CHAR:
			charCase(str);
			break;
		case _INT:
			std::cout << "INT" << std::endl;
			break;
		case _FLOAT:
			std::cout << "_FLOAT" << std::endl;
			break;
		case _DOUBLE:
			std::cout << "_DOUBLE" << std::endl;
			break;
		case _MINUSINF:
			minusInfAndMinusInffCase();
			break;
		case _PLUSINF:
			plusInfAndPlusInffCase();
			break;
		case _NANF:
			nanAndNanfCase();
			break;
		default:
			stringCase();
	}
}


void ft(void)
{
	
}