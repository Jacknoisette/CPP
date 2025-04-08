/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 09:44:30 by codespace         #+#    #+#             */
/*   Updated: 2025/04/08 15:04:17 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream> 
#include <exception>

int	test1(void)
{
	try	{
		Bureaucrat Bureaucrat1("Subject1", 150);
	}
	catch (std::exception & e)	{
		return (std::cout << "ERROR: " << e.what() << std::endl, -1);
	}
	try	{
		Bureaucrat Bureaucrat2("Subject2", 1);
	}
	catch (std::exception & e)	{
		return (std::cout << "ERROR: " << e.what() << std::endl, -1);

	}
	try	{
		Bureaucrat Bureaucrat3("Subject3", 200);
	}
	catch (std::exception & e)	{
		return (std::cout << "ERROR: " << e.what() << std::endl, -1);
	}
	try	{
		Bureaucrat Bureaucrat4("Subject4", 0);
	}
	catch (std::exception & e)	{
		return (std::cout << "ERROR: " << e.what() << std::endl, -1);
	}
	return (0);
}

int	test2(void)
{
	Bureaucrat Subject;
	std::cout << Subject << std::endl;
	try {
		Subject.incrementGrade(140);
		std::cout << Subject << std::endl;
	}
	catch (std::exception & e) {
		return (std::cout << "ERROR: " << e.what() << " at " << Subject << std::endl, -1);
	}
	try {
		Subject.decrementGrade(150);
		std::cout << Subject << std::endl;
	}
	catch (std::exception & e) {
		return (std::cout << "ERROR: " << e.what() << " at " << Subject << std::endl, -1);
	}
	std::cout << Subject << std::endl;
	return (0);
}

int	test3(void)
{
	Bureaucrat Entity1("Tarcuae", 50);
	Bureaucrat Entity2("Rub", 71);
	Bureaucrat Entity3(Entity1);

	std::cout << Entity1 << Entity2 << Entity3 << std::endl;
	Entity3 = Entity2;
	std::cout << Entity1 << Entity2 << Entity3 << std::endl;
	return (0);
}

int main(void)
{
	if (test1() == -1)
		std::cout << "test1 failed" << std::endl;
	if (test2() == -1)
		std::cout << "test2 failed" << std::endl;
	if (test3() == -1)
		std::cout << "test1 failed" << std::endl;
}
