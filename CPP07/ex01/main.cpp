/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 09:44:30 by codespace         #+#    #+#             */
/*   Updated: 2025/05/05 16:44:37 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int	test1(void)
{
	int array[20] = {0, 1, 3, 6, 2, -1, 14, 15, 80, 1000, 4, 54, 23, 83, 1, -1, 93, 90, 138, 100};
	::iter(array, 20, ::printTemplate);
	return (0);
}

int	test2(void)
{
	char array[20] = {'a', '1', '5', '3', '7', '&', 'h', '<', '{', '|', '-', ':', 'p', 'A', '~', '\'', ',', '"', 'K', 'P'};
	::iter(array, 20, ::printTemplate);
	return (0);
}

int	test3(void)
{
	std::string array[15] = {
					"This is the first line",
					"This test will be long to make",
					"I am already bored at the 3rd line", 
					"A wise man said once :",
					"\"A wall that is darker than a white wall",
					"Is not a white wall or you have to clean\"",
					"This man was wise, and for the record",
					"I don't know if a man once said that",
					"And in fact I don't care",
					"The man did what he did",
					"It's not my problem",
					"3 more lines to write",
					"Why man ! Why !",
					"1 more to finish",
					"I hope you enjoyed it because I didn't"};
	::iter(array, 15, ::printTemplate);
	const std::string array_const[15] = {
					"This is the first line",
					"This test will be long to make",
					"I am already bored at the 3rd line", 
					"A wise man said once :",
					"\"A wall that is darker than a white wall",
					"Is not a white wall or you have to clean\"",
					"This man was wise, and for the record",
					"I don't know if a man once said that",
					"And in fact I don't care",
					"The man did what he did",
					"It's not my problem",
					"3 more lines to write",
					"Why man ! Why !",
					"1 more to finish",
					"I hope you enjoyed it because I didn't"};
	::iter(array_const, 15, ::printTemplate);
	return (0);
}

int	test4(int argc, char **argv)
{
	if (argc == 1)
		return (-1);
	::iter(argv + 1, argc - 1, ::printTemplate);
	return (0);
}

int main(int argc, char **argv)
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
	if (test4(argc, argv) == -1)
		std::cout << RED << "test4 was empty" << RESET << std::endl;
	else
		std::cout << LIGHT_GREEN << "test4 OK" << RESET << std::endl;
}
