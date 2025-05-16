/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 09:44:30 by codespace         #+#    #+#             */
/*   Updated: 2025/05/15 10:29:16 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"
#include <iostream> 
#include <exception>

int	test1(void)
{
	Bureaucrat	Administrator("The Administrator", 1);
	Intern		Apprentice;
	AForm		*Form1;

	std::cout << Administrator << std::endl;
	std::cout << Apprentice << std::endl;
	Form1 = Apprentice.makeForm("ShrubberyCreation", "Vegetation");
	if (Form1 == NULL)
		return (-1);
	std::cout << *Form1 << std::endl;
	Form1->beSigned(Administrator);
	std::cout << *Form1 << std::endl;
	Form1->execute(Administrator);
	delete Form1;
	return (0);
}

int	test2(void)
{
	Bureaucrat	Administrator("The Administrator", 1);
	Intern		Apprentice;
	AForm		*Form1;

	std::cout << Administrator << std::endl;
	std::cout << Apprentice << std::endl;
	Form1 = Apprentice.makeForm("RobotomyRequest", "Robot1");
	if (Form1 == NULL)
		return (-1);
	std::cout << *Form1 << std::endl;
	Form1->beSigned(Administrator);
	std::cout << *Form1 << std::endl;
	Form1->execute(Administrator);
	delete Form1;
	return (0);
}

int	test3(void)
{
	Bureaucrat	Administrator("The Administrator", 1);
	Intern		Apprentice;
	AForm		*Form1;

	std::cout << Administrator << std::endl;
	std::cout << Apprentice << std::endl;
	Form1 = Apprentice.makeForm("PresidentialPardon", "Joe");
	if (Form1 == NULL)
		return (-1);
	std::cout << *Form1 << std::endl;
	Form1->beSigned(Administrator);
	std::cout << *Form1 << std::endl;
	Form1->execute(Administrator);
	delete Form1;
	return (0);
}

int	test4(void)
{
	Bureaucrat	Administrator("The Administrator", 1);
	Intern		Apprentice;
	AForm		*Form1;

	std::cout << Administrator << std::endl;
	std::cout << Apprentice << std::endl;
	Form1 = Apprentice.makeForm("ExplodingPlanet", "Earth");
	if (Form1 == NULL)
		return (-1);
	std::cout << *Form1 << std::endl;
	Form1->beSigned(Administrator);
	std::cout << *Form1 << std::endl;
	Form1->execute(Administrator);
	delete Form1;
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
	if (test4() == -1)
		std::cout << RED << "test4 failed" << RESET << std::endl;
	else
		std::cout << LIGHT_GREEN << "test4 OK" << RESET << std::endl;
}
