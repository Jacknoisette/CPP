/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 12:34:45 by jdhallen          #+#    #+#             */
/*   Updated: 2025/03/20 12:52:22 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(void)
{
	PhoneBook	phonebook;
	std::string	str;
	bool		displayEanc = false;

	std::cout << "__________________________________________________________" << std::endl;
	std::cout << "Welcome in the PhoneBook" << std::endl;
	std::cout << "You can enter the following commands :" << std::endl;
	std::cout << "ADD (Add a contact to the Phonebook 8 max)" << std::endl;
	std::cout << "SEARCH (Give you all the informations on a contact 0 - 7)" << std::endl;
	std::cout << "EXIT (Exit the PhoneBook, all informations will be lost)" << std::endl;
	std::cout << "__________________________________________________________" << std::endl;
	phonebook.setContactCount(0);
	std::cout << "\033[1mEnter a command :\033[0m" << std::endl;
	while (1)
	{
		if (displayEanc)
			std::cout << "\033[1mEnter a new command :\033[0m" << std::endl;
		displayEanc = true;
		std::getline(std::cin, str);
		if (std::cin.eof() || std ::cin.fail()){
			std::cout << "EXIT" << std::endl;
			break ;
		}
		if (str == ""){
			std::cout << "\033[F";
			displayEanc = false;
		}
		else if (str == "ADD")
			phonebook.add();
		else if (str == "SEARCH")
			phonebook.search(true);
		else if (str == "EXIT")
			break ;
		else{
			std::cout << "\033[F\033[J";
			displayEanc = false;
		}
		if (std::cin.eof() || std ::cin.fail()){
			std::cout << "\nEXIT" << std::endl;
			break ;
		}
	}
}
