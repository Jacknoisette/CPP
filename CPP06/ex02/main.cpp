/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 09:44:30 by codespace         #+#    #+#             */
/*   Updated: 2025/04/11 11:18:24 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int	test1(void)
{
	std::cout <<"Use of void identify(Base* p)" << std::endl;
	for (int i = 0; i < 10; i++)
	{
		Base base;
		Base *random_class = base.generate();
		base.identify(random_class);
		delete(random_class);
	}
	return (0);
}

int	test2(void)
{
	std::cout <<"Use of void identify(Base& p)" << std::endl;
	for (int i = 0; i < 10; i++)
	{
		Base base;
		Base *random_class = base.generate();
		base.identify(*random_class);
		delete(random_class);
	}
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
}
