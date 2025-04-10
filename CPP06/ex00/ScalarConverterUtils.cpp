/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverterUtils.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 13:58:59 by jdhallen          #+#    #+#             */
/*   Updated: 2025/04/10 15:43:52 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void	display(char character, int integer, float floating, double double_floating, int decimal, std::string *info)
{
	std::ostringstream oss;

	oss.str("");
	if (info[CHAR] == "OK")
		oss << "'" << character << "'";
	else if (info[CHAR] == "KO")
		oss << "impossible";
	else
		oss << "Non displayable";
	std::string	char_string = oss.str();

	std::cout << "char: " << char_string << std::endl;

	oss.str("");
	if (info[INT] == "OK")
		oss << integer;
	else
		oss << "impossible";
	std::string	int_string = oss.str();

	std::cout << "int: " << int_string << std::endl;

	oss.str("");
	if (floating > std::numeric_limits<int>::max())
		oss << std::scientific << std::setprecision(decimal) << floating;
	else
		oss << std::fixed << std::setprecision(decimal) << floating;
	std::string	float_string = oss.str();

	std::cout << "float: " << float_string << "f" << std::endl;

	oss.str("");
	if (double_floating > std::numeric_limits<int>::max())
		oss << std::scientific << std::setprecision(decimal) << double_floating;
	else
		oss << std::fixed << std::setprecision(decimal) << double_floating;
	std::string	double_string = oss.str();
	std::cout << "double: " << double_string << std::endl;
}

void	display_convert(char character, int decimal){
	std::string info[4] = {"OK", "OK", "OK", "OK"};
	(void)decimal;
	int		integer = character;
	float	floating = character;
	double	double_floating = character;
	display(character, integer, floating, double_floating, decimal, info);
}

void	display_convert(int integer, int decimal){
	std::string info[4] = {"OK", "OK", "OK", "OK"};
	(void)decimal;
	std::ostringstream oss;
	if (integer < 0 || integer > 127)
		info[CHAR] = "KO";
	char	character = integer;
	if (!std::isprint(character) && info[CHAR] == "OK")
		info[CHAR] = "N/A";
	float	floating = integer;
	double	double_floating = integer;

	display(character, integer, floating, double_floating, decimal, info);
}
// std::numeric_limits<int>::min()
void	display_convert(float floating, int decimal, bool nan){
	std::string info[2] = {"OK", "OK"};
	std::ostringstream oss;
	if (floating < 0 || floating > 127 || nan)
		info[CHAR] = "KO";
	char	character = static_cast<char>(floating);
	if (!std::isprint(character) && info[CHAR] == "OK")
		info[CHAR] = "N/A";
	if (floating < std::numeric_limits<int>::min() || floating > std::numeric_limits<int>::max() || nan)
		info[INT] = "KO";
	int		integer = floating;
	double	double_floating = floating;

	display(character, integer, floating, double_floating, decimal, info);
}

void	display_convert(double double_floating, int decimal, bool nan){
	std::string info[4] = {"OK", "OK", "OK", "OK"};
	std::ostringstream oss;
	if (double_floating < 0 || double_floating > 127 || nan)
		info[CHAR] = "KO";
	char	character = static_cast<char>(double_floating);
	if (!std::isprint(character) && info[CHAR] == "OK")
		info[CHAR] = "N/A";
	if (double_floating < std::numeric_limits<int>::min() || double_floating > std::numeric_limits<int>::max() || nan)
		info[INT] = "KO";
	int		integer = double_floating;
	float	floating = double_floating;

	display(character, integer, floating, double_floating, decimal, info);
}

int	count_decimal(std::string &input)
{
	int		size = static_cast<int>(input.size());
	int		decimal = 0;
	int i = 0;
	while (i < size && input[i] != '.')
		i++;
	i++;
	while (i < size && std::isdigit(input[i]))
	{
		i++;
		decimal++;
	}
	if (decimal == 0)
		decimal = 1;
	if (decimal > 10)
		decimal = 10;
	return (decimal);
}

void	convertToAllType(std::string &input, void *ptr, int type){	
	char	character = '0';
	int		integer = 0;
	float	floating = 0.0f;
	double	double_floating = 0.0;
	switch (type)
	{
		case 0:
		{
			character = static_cast<char*>(ptr)[0];
			display_convert(character, 1);
			break ;
		}
		case 1:
		{
			integer = static_cast<long*>(ptr)[0];
			display_convert(integer, 1);
			break ;
		}
		case 2:
		{
			bool nanf = false;
			if (input == "nanf")
				nanf = true;
			floating = static_cast<double*>(ptr)[0];
			display_convert(floating, count_decimal(input), nanf);
			break ;
		}
		case 3:
		{
			bool nan = false;
			if (input == "nan")
				nan = true;
			double_floating = static_cast<long double*>(ptr)[0];
			display_convert(double_floating, count_decimal(input), nan);
			break ;
		}
	}
	delete_type(ptr, type);
}