/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 10:57:02 by jdhallen          #+#    #+#             */
/*   Updated: 2025/04/10 15:27:05 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void){
}

ScalarConverter::~ScalarConverter(void){
}

void	ScalarConverter::convert(const std::string &input){
	std::string new_input;
	void	*ptr;
	bool	check_limit = true;
	try{
		new_input = removeWhitespace(input);
	}
	catch (std::runtime_error & error)
	{
		std::cout << "Incorrect type : " << error.what() << std::endl;
		return ;
	}
	int	type = checkOGType(new_input);
	std::string	special_case[] = {"nanf", "-inff", "+inff", "nan", "-inf", "+inf"};
	for (int i = 0; i < 6; i++)
	{
		if (new_input == special_case[i])
		{
			check_limit = false;
			return ;
		}
	}
	if (check_limit == true)
	{
		try{
			ptr = checkLimitType(new_input, type);
		}
		catch (std::runtime_error & error)
		{
			std::cout << "Incorrect type : " << error.what() << std::endl;
			return ;
		}
	}
	else {
		ptr = checkLimitTypeSpe(new_input, type);
	}
	convertToAllType(new_input, ptr, type);
	display_type(type);
}