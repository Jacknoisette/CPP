/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 09:44:30 by codespace         #+#    #+#             */
/*   Updated: 2025/04/10 15:20:44 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream> 

int	test1(void)
{
	std::cout << WHITE << "CHAR" << RESET << std::endl;
	std::cout << "_______________" << std::endl;
	ScalarConverter::convert("a");
	std::cout << "_______________" << std::endl;
	ScalarConverter::convert("A");
	std::cout << WHITE << "INT" << RESET << std::endl;
	std::cout << "_______________" << std::endl;
	ScalarConverter::convert("+14511");
	std::cout << "_______________" << std::endl;
	ScalarConverter::convert("10");
	std::cout << "_______________" << std::endl;
	ScalarConverter::convert("-10");
	std::cout << WHITE << "FLOAT" << RESET << std::endl;
	std::cout << "_______________" << std::endl;
	ScalarConverter::convert("145.0f");
	std::cout << "_______________" << std::endl;
	ScalarConverter::convert("nanf");
	std::cout << "_______________" << std::endl;
	ScalarConverter::convert("-inff");
	std::cout << "_______________" << std::endl;
	ScalarConverter::convert("+inff");
	std::cout << WHITE << "DOUBLE" << RESET << std::endl;
	std::cout << "_______________" << std::endl;
	ScalarConverter::convert("1e+308");
	std::cout << "_______________" << std::endl;
	ScalarConverter::convert("nan  ");
	std::cout << "_______________" << std::endl;
	ScalarConverter::convert("  -inf");
	std::cout << "_______________" << std::endl;
	ScalarConverter::convert("  +inf  ");
	std::cout << WHITE << "INCORRECT" << RESET << std::endl;
	std::cout << "_______________" << std::endl;
	ScalarConverter::convert("145.0 0");
	std::cout << "_______________" << std::endl;
	ScalarConverter::convert("hello");
	std::cout << "_______________" << std::endl;
	ScalarConverter::convert("-2147483649");
	std::cout << "_______________" << std::endl;
	ScalarConverter::convert("1e+309");
	return (0);
}

int	test2(void)
{
	return (0);
}

int	test3(void)
{
	return (0);
}

int main(void)
{
	int	test;
	
	if (test1() == -1)
		std::cout << RED << "test1 failed" << RESET << std::endl;
	else
		std::cout << LIGHT_GREEN << "test1 OK" << RESET << std::endl;
	test = test2();
	if (test > 0)
		std::cout << RED << "test2 failed with " << test << " errors" << RESET << std::endl;
	else
		std::cout << LIGHT_GREEN << "test2 OK" << RESET << std::endl;
	if (test3() == -1)
		std::cout << RED << "test3 failed" << RESET << std::endl;
	else
		std::cout << LIGHT_GREEN << "test3 OK" << RESET << std::endl;
}
