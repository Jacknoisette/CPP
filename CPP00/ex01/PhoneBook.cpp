/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:06:19 by jdhallen          #+#    #+#             */
/*   Updated: 2025/03/18 11:14:45 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void){
	contactCount = 0;
}

PhoneBook::~PhoneBook(void){
}

void PhoneBook::addContact(const Contact& newContact){
	contact[contactCount % 8] = newContact;
}

void PhoneBook::displayPhoneBook(void){
	for (int i = 0; i < 8; i++)
		contact[i].display();
}

void	PhoneBook::add(void){
	Contact	new_contact;
	
	new_contact.changeContact();
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

void	PhoneBook::search(void)
{
	std::string	str;
	int			result;
	
	printSearch();
	std::cout << "ENTER CONTACT INDEX : ";
	std::getline(std::cin, str);
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
		{
			std::cout << "\033[34mERROR : WRONG CHAR\033[0m" << std::endl;
			return ;
		}
	}
	result = atoi(str.c_str());
	if (result < 8 && result > -1)
		contact[result].display();
	else
		std::cout << "\033[34mERROR : INCORRECT INPUT\033[0m" << std::endl;
}

int main(void)
{
	PhoneBook	phonebook;
	std::string	str;

	std::cout << "Welcome in the PhoneBook" << std::endl;
	std::cout << "Here you can do the following actions :" << std::endl;
	std::cout << "ADD (Add a contact to the Phonebook 8 max)" << std::endl;
	std::cout << "SEARCH (Give you all the informations on a contact 0 - 7)" << std::endl;
	std::cout << "EXIT (Exit the PhoneBook, all informations will be lost)\n" << std::endl;
	phonebook.contactCount = 0;
	while (1)
	{
		std::getline(std::cin, str);
		if (std::cin.eof() || std ::cin.fail())
			break ;
		if (str == "")
			std::cout << "\033[F";
		else if (str == "ADD")
			phonebook.add();
		else if (str == "SEARCH")
			phonebook.search();
		else if (str == "EXIT")
			break ;
		else if (str == "EXIT")
			break ;
		else
			std::cout << "\033[F\033[J";
	}
}