/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 10:57:02 by jdhallen          #+#    #+#             */
/*   Updated: 2025/06/03 11:28:17 by jdhallen         ###   ########.fr       */
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

	try{
		new_input = removeWhitespace(input);
	}
	catch (std::runtime_error & error)
	{
		std::cout << "Incorrect type : " << error.what() << std::endl;
		return ;
	}
	int	type = checkOGType(new_input);
	if (type == DEFAULT){
		std::cout << "Incorrect type" << std::endl, 0;
		return ;
	}
	display_type(type);
	try{
		ptr = checkLimitType(new_input, type);
	}
	catch (std::runtime_error & error)
	{
		std::cout << "Incorrect type : " << error.what() << std::endl;
		return ;
	}
	convertToAllType(new_input, ptr, type);
}
// display_type(type);