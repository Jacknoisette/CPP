/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 15:03:30 by jdhallen          #+#    #+#             */
/*   Updated: 2025/04/09 16:08:59 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

//Intern
Intern::Intern(void){
}

Intern::~Intern(void){	
}

Intern::Intern(const Intern &copy){
	*this = copy;
}

Intern &Intern::operator=(const Intern &src){
	(void)src;
	return (*this);
}

AForm	*Intern::makeForm(std::string name, std::string target){

	std::string	name_lower = name;
	for (int i = 0; name_lower[i]; i++)
		name_lower[i] = std::tolower(name_lower[i]);
	std::string	name_nws;
	for (int i = 0; name[i]; i++)
	{
		while (name[i] == '\t' || name[i] == ' ')
			i++;
		name_nws += name_lower[i];
	}
	std::string type[3] = {"shrubberycreation", "robotomyrequest", "presidentialpardon"};
	AForm		*Form[3] = {new ShrubberyCreationForm(name, target), new RobotomyRequestForm(name, target), new PresidentialPardonForm(name, target)};
	for (int i = 0; i < 3; i++)
	{
		if (name_nws == type[i])
		{
			for (int j = 0; j < 3; j++)
				if (j != i)
					delete Form[j];
			std::cout << "Intern creates " << name << std::endl;
			return (Form[i]);
		}
	}
	for (int j = 0; j < 3; j++)
		delete Form[j];
	std::cout << "Intern can't create " << name << " with target " << target << std::endl;
	return (NULL);
}

std::ostream& operator<<(std::ostream& output, Intern& obj){
	(void)obj;
	output << "Intern is working. ";
	return (output);
}
