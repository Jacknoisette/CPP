/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 09:44:12 by codespace         #+#    #+#             */
/*   Updated: 2025/03/18 13:31:07 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void): type("Unknown type"){
	std::cout << "An Animal " << type << " have spawn !" << std::endl;	
}

Animal::Animal(std::string _type): type(_type){
	std::cout << "An Animal " << type << " have spawn !" << std::endl;	
}
		
Animal::~Animal(void){
	std::cout << "An Animal " << type << " have despawn !" << std::endl;
}

Animal::Animal(const Animal &copy){
	*this = copy;
	std::cout << "Construction of Animal copy " << this->type << std::endl;
}

Animal &Animal::operator=(const Animal &src){
	std::cout << "Operator Animal " << this->type << " = " << src.type << std::endl;
	this->type = src.type;
	return *this;
}


std::string Animal::getType(void) const{
	return type;
}

void	Animal::makeSound(void) const{
	std::cout << "Grrrrr !" << std::endl;
}