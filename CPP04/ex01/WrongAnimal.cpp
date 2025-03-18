/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 10:49:24 by codespace         #+#    #+#             */
/*   Updated: 2025/03/18 10:58:47 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void){
	type = "Unknown wrongtype";
	std::cout << "An WrongAnimal " << type << " have spawn !" << std::endl;	
}

WrongAnimal::WrongAnimal(std::string _type){
	type = _type;
	std::cout << "An WrongAnimal " << type << " have spawn !" << std::endl;	
}
		
WrongAnimal::~WrongAnimal(void){
	std::cout << "An WrongAnimal " << type << " have despawn !" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy){
	*this = copy;
	std::cout << "Construction of WrongAnimal copy " << this->type << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &src){
	std::cout << "Operator WrongAnimal " << this->type << " = " << src.type << std::endl;
	this->type = src.type;
	return *this;
}


std::string WrongAnimal::getType(void) const{
	return type;
}

void	WrongAnimal::makeSound(void) const{
	std::cout << "Grrrrr !" << std::endl;
}