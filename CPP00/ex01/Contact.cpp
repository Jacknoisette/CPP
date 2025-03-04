/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 17:32:33 by jdhallen          #+#    #+#             */
/*   Updated: 2025/03/04 18:16:27 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

std::string	Contact::getFirstName(void) const{
	return firstName;
}

std::string	Contact::getLastName(void) const{
	return lastName;
}

std::string	Contact::getNickname(void) const{
	return nickname;
}

std::string	Contact::getPhoneNumber(void) const{
	return phoneNumber;
}

std::string	Contact::getDarkestSecret(void) const{
	return darkestSecret;
}

void	Contact::setFirstName(std::string str){
	firstName = str;
}

void	Contact::setLastName(std::string str){
	lastName = str;
}

void	Contact::setNickname(std::string str){
	nickname = str;
}

void	Contact::setPhoneNumber(std::string str){
	phoneNumber = str;
}

void	Contact::setDarkestSecret(std::string str){
	darkestSecret = str;
}

void Contact::changeContact(void)
{
	std::string	str;
	int			test = 6;
	
	std::cout << "Enter first name: ";
	std::getline(std::cin >> std::ws, str);
	setFirstName(str);
	std::cout << "Enter last name: ";
	std::getline(std::cin, str);
	setLastName(str);
	std::cout << "Enter nickname: ";
	std::getline(std::cin, str);
	setNickname(str);
	std::cout << "Enter phoneNumber: ";
	std::getline(std::cin, str);
	setPhoneNumber(str);
	std::cout << "Enter darkest secret: ";
	std::getline(std::cin, str);
	setDarkestSecret(str);
}

void Contact::display(void) const
{
	std::cout << "First name: " << getFirstName() << std::endl;
	std::cout << "Last name: " << getLastName() << std::endl;
	std::cout << "Nickname: " << getNickname() << std::endl;
	std::cout << "Phone number: " << getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << getDarkestSecret() << std::endl;
}
