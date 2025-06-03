/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverterParsing.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 13:51:31 by jdhallen          #+#    #+#             */
/*   Updated: 2025/06/03 11:28:01 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

std::string removeWhitespace(const std::string &input){
	std::string	input_nws;
	int		size = static_cast<int>(input.size());
	int		i = 0;
	if (size == 1 && (input[i] == ' '))
		return (input);
	if (size > 1 && (input[i] == '\'' || input[i] == '\"'))
		throw std::runtime_error("Incorrect not a char, int, float or double");
	while (i < size && std::isspace(input[i]))
		i++;
	while (i < size && !std::isspace(input[i]))
	{
		input_nws += input[i];
		i++;
	}
	while (i < size && std::isspace(input[i]))
		i++;
	if (i < size)
		throw std::runtime_error("Incorrect not a char, int, float or double");
	return (input_nws);
}

int	 checkOGType(const std::string &input){
	bool	contains_e = false;
	bool	contains_float = false;
	int		e_after_decimal = -1;
	int		size = static_cast<int>(input.size());
	if (size == 0)
		return (DEFAULT);
	if (size == 1 && std::isprint(input[0]))
		return (CHAR);
	std::string	special_case[] = {"nanf", "-inff", "+inff", "nan", "-inf", "+inf"};
	for (int i = 0; i < 6; i++)
	{
		if (input == special_case[i])
		{
			if (i >= 0 && i <= 2)
				return (FLOAT);
			else
				return (DOUBLE);
		}
	}
	if (size > 1 && !std::isdigit(input[0]))
		return (DEFAULT);
	for (int i = 0; i < size; i++)
	{
		if (i == 0 && (input[i] == '-' || input[i] == '+'))
			continue ;
		if (input[i] == '.')
			contains_float = true;
		else if (input[i] == 'e')
		{
			if (i < size - 1 && !contains_e)
			{
				if (input[i + 1] == '.') 
					return (DEFAULT);
				if (contains_float == true)
					e_after_decimal = 1;
				else
					e_after_decimal = 0;
				contains_e = true;
				continue ;
			}
			else
				return (DEFAULT);
		}
		else if (input[i] == '+')
		{
			if (input[i - 1] == 'e')
				continue;
			else
				return (DEFAULT);
		}
		else if (!std::isdigit(input[i]))
		{
			if (i == size - 1 && input[i] == 'f')
				return (FLOAT);
			else
				return (DEFAULT);
		}
	}
	if (e_after_decimal == 0 && contains_float)
		return (DEFAULT);
	if (input[size - 1] == 'f')
		return (FLOAT);
	else if (contains_e || contains_float)
		return (DOUBLE);
	else
		return (INT);
	return (DEFAULT);
}

void	*checkLimitType(const std::string &input, int type){
	char	*end;
	errno = 0;
	switch (type)
	{
		case 0:
		{
			char	*character = new char(input[0]);
			return (character);
		}
		case 1:
		{
			long	integer_tmp = std::strtol(input.c_str(), &end, 10);
			if (errno == ERANGE || integer_tmp < std::numeric_limits<int>::min() || integer_tmp > std::numeric_limits<int>::max())
				throw std::runtime_error("Incorrect int");
			int	*integer = new int(static_cast<int>(integer_tmp));
			return (integer);
		}
		case 2:
		{
			double floating_tmp;
			if (input == "nanf"){
				floating_tmp = NAN;
			} else if (input == "+inff"){
				floating_tmp = INFINITY; 
			} else if (input == "-inff"){
				floating_tmp = -INFINITY;
			} else {
				floating_tmp = std::strtod(input.c_str(), &end);
				if (errno == ERANGE || floating_tmp < -std::numeric_limits<float>::max() || floating_tmp > std::numeric_limits<float>::max())
					throw std::runtime_error("Incorrect float");
			}
			float *floating = new float(static_cast<float>(floating_tmp));
			return (floating);
		}
		case 3:
		{
			long double	double_floating_tmp;
			if (input == "nan"){
				double_floating_tmp = NAN;
			} else if (input == "+inf"){
				double_floating_tmp = INFINITY; 
			} else if (input == "-inf"){
				double_floating_tmp = -INFINITY;
			} else {
				double_floating_tmp = std::strtold(input.c_str(), &end);
				if (errno == ERANGE || double_floating_tmp < -std::numeric_limits<double>::max() || double_floating_tmp > std::numeric_limits<double>::max())
					throw std::runtime_error("Incorrect double");
			}
			double *double_floating= new double(static_cast<double>(double_floating_tmp));
			return (double_floating);
		}
		default :
			break ;
	}
	return (NULL);
}

void	display_type(int type){
	switch (type)
	{
		case 0:
		{
			std::cout << "Type is CHAR" << std::endl;
			break ;
		}
		case 1:
		{
			std::cout << "Type is INT" << std::endl;
			break ;
		}
		case 2:
		{
			std::cout << "Type is FLOAT" << std::endl;
			break ;
		}
		case 3:
		{
			std::cout << "Type is DOUBLE" << std::endl;
			break ;
		}
		default :
		{
			std::cout << "Incorrect type" << std::endl;
			break ;
		}
	}
}

void	delete_type(void *ptr, int type)
{
	switch (type)
	{
		case 0:
		{
			delete static_cast<char*>(ptr);
			break ;
		}
		case 1:
		{
			delete static_cast<int*>(ptr);
			break ;
		}
		case 2:
		{
			delete static_cast<float*>(ptr);
			break ;
		}
		case 3:
		{
			delete static_cast<double*>(ptr);
			break ;
		}
	}
}