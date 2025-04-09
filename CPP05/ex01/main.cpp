/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 09:44:30 by codespace         #+#    #+#             */
/*   Updated: 2025/04/09 13:56:35 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream> 
#include <exception>

int	test1(void)
{
	try	{
		Form Form1("Document1", 150, 100);
	}
	catch (std::exception & e)	{
		return (std::cout << RED << "ERROR1: " << e.what() << RESET << std::endl, -1);
	}
	try	{
		Form Form2("Document2", 10, 1);
	}
	catch (std::exception & e)	{
		return (std::cout << RED << "ERROR2: " << e.what() << RESET << std::endl, -1);

	}
	try	{
		Form Form3("Document3", 200, 150);
	}
	catch (std::exception & e)	{
		return (std::cout << RED << "ERROR3: " << e.what() << RESET << std::endl, -1);
	}
	try	{
		Form Formt4("Document4", 0, -1);
	}
	catch (std::exception & e)	{
		return (std::cout << RED << "ERROR4: " << e.what() << RESET << std::endl, -1);
	}
	return (0);
}

int	test2(void)
{
	Bureaucrat	Guy("Guy the Form guy", 101);
	Form		File1;
	Form		File2("Classic Form", 100, 80);
	std::cout << File1 << std::endl;
	std::cout << File2 << std::endl;
	std::cout << Guy << std::endl;
	try {
		File1.beSigned(Guy);
		std::cout << File1 << std::endl;
		std::cout << Guy << std::endl;
	}
	catch (std::exception & e) {
		return (std::cout << RED << "ERROR: " << e.what() << " at " << File1 << RESET << std::endl, -1);
	}
	try {
		Guy.signForm(File2);
		std::cout << File2 << std::endl;
		std::cout << Guy << std::endl;
	}
	catch (std::exception & e) {
		return (std::cout << RED << "ERROR: " << e.what() << " at " << File2 << RESET << std::endl, -1);
	}
	std::cout << File1 << std::endl;
	std::cout << File2 << std::endl;
	std::cout << Guy << std::endl;
	return (0);
}

int	test3(void)
{
	Bureaucrat	Emperor("The Emperor", 1);
	Form		Thing1("the OG Form", 50, 40);
	Form		Thing2("the Other Form not the OG one", 71, 60);
	Form 		Thing3(Thing1);

	std::cout << WHITE << Thing1 << RESET << std::endl;
	std::cout << LIGHT_YELLOW << Thing2 << RESET << std::endl;
	std::cout << GREY << Thing3 << RESET << std::endl;
	Thing2.beSigned(Emperor);
	Thing3 = Thing2;
	std::cout << WHITE << Thing1 << RESET << std::endl;
	std::cout << LIGHT_YELLOW << Thing2 << RESET << std::endl;
	std::cout << GREY << Thing3 << RESET << std::endl;
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
