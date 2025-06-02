/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 09:44:30 by codespace         #+#    #+#             */
/*   Updated: 2025/06/02 14:41:00 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int	test1(void)
{
	Array<int> array(10);

	for (unsigned int i = 0; i < array.size(); i++)
	{
		try	{
			array[i] = i;
		}
		catch(const std::exception& e){
			return (-1);
		}
		std::cout << array[i] << std::endl;
	}
	return (0);
}

int	test2(void)
{
	Array<int> array;

	for (unsigned int i = 0; i < array.size() + 1; i++)
	{
		try	{
			array[i] = i;
		}
		catch(const std::exception& e){
			return (-1);
		}
		std::cout << array[i] << std::endl;
	}
	return (0);
}

int	test3(void)
{
	Array<char> array(10);

	std::cout << WHITE << BIG << "OG after cpy sup" << RESET << std::endl;

	for (unsigned int i = 0; i < array.size(); i++)
	{
		try	{
			array[i] = '0' + i;
		}
		catch(const std::exception& e){
			return (-1);
		}
		std::cout << array[i] << std::endl;
	}
	std::cout << WHITE << BIG << "CPY" << RESET << std::endl;
	{
		Array<char> arraycopy(array);
		for (unsigned int i = 0; i < arraycopy.size(); i++)
		{
			std::cout << arraycopy[i] << std::endl;
		}
		std::cout << "reverse the CPY" << std::endl;
		for (unsigned int i = 0; i < arraycopy.size(); i++)
		{
			arraycopy[i] = '9'- i;
			std::cout << arraycopy[i] << std::endl;
		}
	}
	std::cout << WHITE << BIG << "OG after cpy sup" << RESET << std::endl;
	for (unsigned int i = 0; i < array.size(); i++)
	{
		std::cout << array[i] << std::endl;
	}
	return (0);
}

int main(void)
{
	if (test1() == -1)
		std::cout << RED << "test1 failed" << RESET << std::endl;
	else
		std::cout << LIGHT_GREEN << "test1 OK" << RESET << std::endl;
	if (test2() == -1)
		std::cout << RED << "test2 failed" << RESET << std::endl;
	else
		std::cout << LIGHT_GREEN << "test2 OK" << RESET << std::endl;
	if (test3() == -1)
		std::cout << RED << "test3 failed" << RESET << std::endl;
	else
		std::cout << LIGHT_GREEN << "test3 OK" << RESET << std::endl;
}
