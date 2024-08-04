/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 16:18:29 by zelabbas          #+#    #+#             */
/*   Updated: 2024/08/04 15:04:24 by zelabbas         ###   ########.fr       */
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

int	ScalarConverter::detectType(const std::string &str) {
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

int ScalarConverter::AnoramlType(const std::string& str) {
	if (!str.compare("-inff") || !str.compare("-inf"))
		return (_MINUSINF);
	if (!str.compare("+inff") || !str.compare("+inf"))
		return (_PLUSINF);
	if (!str.compare("nanf") || !str.compare("nan"))
		return (_NANF);
	return (_STRING);
}

int	ScalarConverter::getType(const std::string& str) {
	int	_type;

	_type = detectType(str);
	if (_type != _STRING)
		return (_type);
	return (AnoramlType(str));
}

void	ScalarConverter::charCase(const std::string& str) {
	char _char;

	_char = static_cast<char>(str[0]);
	if (isprint(_char) && !isdigit(_char))
		std::cout << "char: '" << _char << "'" << std::endl;
	else
	{
		if (isdigit(_char))
			_char = static_cast<char>(_char - '0');
		std::cout << "char: " << "Non displayable" << std::endl;
	}
	std::cout << "int: " << static_cast<int>(_char) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(_char) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(_char) << std::endl;
}

void	ScalarConverter::intCase(const std::string& str) {
	int	number;
	std::stringstream	ssInt(str);

	ssInt >> number;
	if (ssInt.fail())
	{
		std::cout << "the number: " << str << " is out of range int" << std::endl;
		return ;
	}
	if (isprint(number))
		std::cout << "char: '" << static_cast<char> (number) << "'" << std::endl;
	else
		std::cout << "char: " << "Non displayable" << std::endl;
	std::cout << "int: " << number << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(number) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(number) << std::endl;
}

void	ScalarConverter::floatCase(const std::string& str) {
	float	number;
	std::string copyString;

	copyString = str;
	copyString[copyString.length() - 1] = '\0';
	std::stringstream	ssFloat(copyString);

	ssFloat >> number;
	if (ssFloat.fail())
	{
		std::cout << "the number: " << str << " is out of range float" << std::endl;
		return ;
	}
	if (isprint(number))
		std::cout << "char: '" << static_cast<char> (number) << "'" << std::endl;
	else
		std::cout << "char: " << "Non displayable" << std::endl;
	if (number < std::numeric_limits<int>::min() || number > std::numeric_limits<int>::max())
		std::cout << "int: out of range" << std::endl;
	else
		std::cout << "int: " << static_cast<int> (number) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << number << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(number) << std::endl;
}

void	ScalarConverter::doubleCase(const std::string& str) {
	double	number;
	std::stringstream	ssDouble(str);

	ssDouble >> number;
	if (ssDouble.fail())
	{
		std::cout << "the number: " << str << " is out of range double" << std::endl;
		return ;
	}
	if (isprint(number))
		std::cout << "char: '" << static_cast<char> (number) << "'" << std::endl;
	else
		std::cout << "char: " << "Non displayable" << std::endl;
	if (number < std::numeric_limits<int>::min() || number > std::numeric_limits<int>::max())
		std::cout << "int: out of range" << std::endl;
	else
		std::cout << "int: " << static_cast<int> (number) << std::endl;
	if (number < std::numeric_limits<float>::min() || number > std::numeric_limits<float>::max())
		std::cout << "float: out of range" << std::endl;
	else
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(number) << "f" << std::endl;
	std::cout << "double: " << number << std::endl;
}

void	ScalarConverter::stringCase(void) {
	std::cout << "char: " << "converter Impossible" << std::endl;
	std::cout << "int: " << "converter Impossible" << std::endl;
	std::cout << "float: " << "converter Impossible" << std::endl;
	std::cout << "double: " << "converter Impossible" << std::endl;
}

void	ScalarConverter::minusInfAndMinusInffCase(void) {
	std::cout << "char: " << "converter Impossible" << std::endl;
	std::cout << "int: " << "converter Impossible" << std::endl;
	std::cout << "float: " << "-inff" << std::endl;
	std::cout << "double: " << "-inf" << std::endl;
}

void	ScalarConverter::plusInfAndPlusInffCase(void) {
	std::cout << "char: " << "converter Impossible" << std::endl;
	std::cout << "int: " << "converter Impossible" << std::endl;
	std::cout << "float: " << "+inff" << std::endl;
	std::cout << "double: " << "+inf" << std::endl;
}

void	ScalarConverter::nanAndNanfCase(void) {
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
			intCase(str);
			break;
		case _FLOAT:
			floatCase(str);
			break;
		case _DOUBLE:
			doubleCase(str);
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
