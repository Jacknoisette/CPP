/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 10:51:31 by codespace         #+#    #+#             */
/*   Updated: 2025/03/18 13:21:45 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void): WrongAnimal("WrongCat"), type("WrongCat"){
	std::cout << "A " << type << " have spawn !" << std::endl;	
}
		
WrongCat::~WrongCat(void){
	std::cout << "A " << type << " have despawn !" << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy): WrongAnimal("WrongCat"){
	*this = copy;
	std::cout << "Construction of WrongCat copy " << this->type << std::endl;
}

WrongCat	&WrongCat::operator=(const WrongCat &src){
	std::cout << "Operator WrongCat " << this->type << " = " << src.type << std::endl;
	this->type = src.type;
	return *this;
}

std::string WrongCat::getType(void) const{
	return type;
}

void	WrongCat::makeSound(void) const{
	std::cout << "Meaaaaw !" << std::endl;
}