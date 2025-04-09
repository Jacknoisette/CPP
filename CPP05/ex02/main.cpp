/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 09:44:30 by codespace         #+#    #+#             */
/*   Updated: 2025/04/09 14:47:32 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream> 
#include <exception>

int	test1(void)
{
	try	{
		PresidentialPardonForm PPF1("Document1", "Guy");
	}
	catch (std::exception & e)	{
		return (std::cout << RED << "ERROR1: " << e.what() << RESET << std::endl, -1);
	}
	try	{
		RobotomyRequestForm RRF1("Document2", "Tobor");
	}
	catch (std::exception & e)	{
		return (std::cout << RED << "ERROR2: " << e.what() << RESET << std::endl, -1);

	}
	try	{
		ShrubberyCreationForm SCF1("Document3", "Small bush in the corner");
	}
	catch (std::exception & e)	{
		return (std::cout << RED << "ERROR3: " << e.what() << RESET << std::endl, -1);
	}
	return (0);
}

int	test2(void)
{
	int			Error = 0;
	
	Bureaucrat	Random;
	Bureaucrat	Guy("Guy the Form guy", 120);
	Bureaucrat	Man("Man the Form man", 30);
	Bureaucrat	Emperor("Emperor the Form emperor", 1);

	PresidentialPardonForm	PPF2;
	RobotomyRequestForm		RRF2;
	ShrubberyCreationForm	SCF2;
	std::cout << ORANGE << Random << std::endl;
	std::cout << Guy << std::endl;
	std::cout << Man << std::endl;
	std::cout << Emperor << std::endl;
	std::cout << PPF2 << std::endl;
	std::cout << RRF2 << std::endl;
	std::cout << SCF2 << RESET << std::endl;

	Emperor.signForm(PPF2);
	Emperor.signForm(RRF2);
	Emperor.signForm(SCF2);

	try {
		Random.executeForm(PPF2);
		std::cout << PPF2 << std::endl;
		std::cout << Random << std::endl;
	}
	catch (std::exception & e) {
		Error++;
		std::cout << RED << "ERROR: " << e.what() << RESET << std::endl;
	}
	try {
		RRF2.execute(Random);
		std::cout << RRF2 << std::endl;
		std::cout << Random << std::endl;
	}
	catch (std::exception & e) {
		Error++;
		std::cout << RED << "ERROR: " << e.what() << RESET << std::endl;
	}
	try {
		Random.executeForm(SCF2);
		std::cout << SCF2 << std::endl;
		std::cout << Random << std::endl;
	}
	catch (std::exception & e) {
		Error++;
		std::cout << RED << "ERROR: " << e.what() << RESET << std::endl;
	}
	std::cout << ORANGE << Random << std::endl;
	std::cout << Guy << std::endl;
	std::cout << Man << std::endl;
	std::cout << Emperor << std::endl;
	std::cout << PPF2 << std::endl;
	std::cout << RRF2 << std::endl;
	std::cout << SCF2 << RESET << std::endl;
	try {
		PPF2.execute(Emperor);
		std::cout << PPF2 << std::endl;
		std::cout << Emperor << std::endl;
	}
	catch (std::exception & e) {
		Error++;
		std::cout << RED << "ERROR: " << e.what() << RESET << std::endl;
	}
	try {
		for (int i = 0; i < 5; i++)
			Man.executeForm(RRF2);
		std::cout << RRF2 << std::endl;
		std::cout << Random << std::endl;
	}
	catch (std::exception & e) {
		Error++;
		std::cout << RED << "ERROR: " << e.what() << RESET << std::endl;
	}
	try {
		SCF2.execute(Guy);
		std::cout << SCF2 << std::endl;
		std::cout << Guy << std::endl;
	}
	catch (std::exception & e) {
		Error++;
		std::cout << RED << "ERROR: " << e.what() << RESET << std::endl;
	}
	std::cout << ORANGE << Random << std::endl;
	std::cout << Guy << std::endl;
	std::cout << Man << std::endl;
	std::cout << Emperor << std::endl;
	std::cout << PPF2 << std::endl;
	std::cout << RRF2 << std::endl;
	std::cout << SCF2 << RESET << std::endl;
	return (Error);
}

int	test3(void)
{
	Bureaucrat	King("The King", 1);
	{
		ShrubberyCreationForm	Thing1("the OG Form", "Bush");
		ShrubberyCreationForm	Thing2("the Other Form not the OG one", "Rock");
		ShrubberyCreationForm	Thing3(Thing1);

		std::cout << WHITE << Thing1 << RESET << std::endl;
		std::cout << LIGHT_YELLOW << Thing2 << RESET << std::endl;
		std::cout << GREY << Thing3 << RESET << std::endl;
		Thing2.beSigned(King);
		Thing3 = Thing2;
		std::cout << WHITE << Thing1 << RESET << std::endl;
		std::cout << LIGHT_YELLOW << Thing2 << RESET << std::endl;
		std::cout << GREY << Thing3 << RESET << std::endl;
	}
	{
		RobotomyRequestForm	Thing1("the OG Form", "Robot1");
		RobotomyRequestForm	Thing2("the Other Form not the OG one", "Robot2");
		RobotomyRequestForm	Thing3(Thing1);

		std::cout << WHITE << Thing1 << RESET << std::endl;
		std::cout << LIGHT_YELLOW << Thing2 << RESET << std::endl;
		std::cout << GREY << Thing3 << RESET << std::endl;
		Thing2.beSigned(King);
		Thing3 = Thing2;
		std::cout << WHITE << Thing1 << RESET << std::endl;
		std::cout << LIGHT_YELLOW << Thing2 << RESET << std::endl;
		std::cout << GREY << Thing3 << RESET << std::endl;
	}
	{
		PresidentialPardonForm		Thing1("the OG Form", "Bob");
		PresidentialPardonForm		Thing2("the Other Form not the OG one", "John");
		PresidentialPardonForm 		Thing3(Thing1);

		std::cout << WHITE << Thing1 << RESET << std::endl;
		std::cout << LIGHT_YELLOW << Thing2 << RESET << std::endl;
		std::cout << GREY << Thing3 << RESET << std::endl;
		Thing2.beSigned(King);
		Thing3 = Thing2;
		Thing3.execute(King);
		std::cout << WHITE << Thing1 << RESET << std::endl;
		std::cout << LIGHT_YELLOW << Thing2 << RESET << std::endl;
		std::cout << GREY << Thing3 << RESET << std::endl;
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
	if (test3() == -1)
		std::cout << RED << "test3 failed" << RESET << std::endl;
	else
		std::cout << LIGHT_GREEN << "test3 OK" << RESET << std::endl;
}
