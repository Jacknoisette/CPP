/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:06:19 by jdhallen          #+#    #+#             */
/*   Updated: 2025/03/20 12:51:52 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void){
	contactCount = 0;
}

PhoneBook::~PhoneBook(void){
}

int	PhoneBook::getContactCount(void) const{
	return contactCount;
}

void	PhoneBook::setContactCount(int nbr){
	contactCount = nbr;
}

void PhoneBook::addContact(const Contact& newContact){
	contact[contactCount % 8] = newContact;
	std::cout << newContact.getFirstName() << " added [" << (contactCount % 8) + 1 << "/8]" << std::endl;
}

void PhoneBook::displayPhoneBook(void){
	for (int i = 0; i < 8; i++)
		contact[i].display();
}

void	PhoneBook::add(void){
	Contact	new_contact;
	
	try {
		new_contact.changeContact();
	} catch (const std::runtime_error &e){
		return ;
	}
	addContact(new_contact);
	contactCount++;
}

void	printCase(std::string temp)
{
	if (temp.length() > 10)
		temp = temp.substr(0, 9) + ".";
	std::cout << std::setw(10) << temp << "|";
}

void	PhoneBook::printRow(int row)
{
	std::string str;
	std::stringstream ss;
	
	ss << row; str = ss.str();
	std::cout << "|";
	printCase(str);
	printCase(contact[row].getFirstName());
	printCase(contact[row].getLastName());
	printCase(contact[row].getNickname());
	std::cout << std::endl;	
}

void	PhoneBook::printSearch(void)
{
	std::cout << "\033[4m" << std::setw(12);
	std::cout << "" << std::setw(11);
	std::cout << "" << std::setw(11);
	std::cout << "" << std::setw(11);
	std::cout << "" << std::endl << "|";
	printCase("id");
	printCase("firstName");
	printCase("lastName");
	printCase("nickname");
	std::cout << std::endl;	
	for (int row = 0; row < 8; row++)
		printRow(row);
	std::cout << "\033[0m";
}

void	PhoneBook::search(bool print)
{
	std::string	str;
	int			result;
	
	if (print)
		printSearch();
	do {
		std::cout << "ENTER CONTACT INDEX : ";
		std::getline(std::cin, str);
		if (std::cin.eof() || std ::cin.fail())
			return ;
	} while (str.empty());
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
		{
			std::cout << "\033[34mERROR : WRONG CHAR\033[0m" << std::endl;
			search(false);
			return ;
		}
	}
	result = atoi(str.c_str());
	if (result < 8 && result > -1)
		contact[result].display();
	else
		std::cout << "\033[34mERROR : INCORRECT INPUT\033[0m" << std::endl;
}

