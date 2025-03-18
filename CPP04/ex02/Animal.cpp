/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 09:44:12 by codespace         #+#    #+#             */
/*   Updated: 2025/03/18 14:37:29 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void): type("Unknown type"){
	std::cout << COLORA << "An Animal " << type << " have spawn !" << RESET << std::endl;	
}

Animal::Animal(std::string _type): type(_type){
	std::cout << COLORA << "An Animal " << type << " have spawn !" << RESET << std::endl;	
}
		
Animal::~Animal(void){
	std::cout << COLORA << "An Animal " << type << " have despawn !" << RESET << std::endl;
}

Animal::Animal(const Animal &copy){
	*this = copy;
	std::cout << COLORA << "Construction of Animal copy " << this->type << RESET << std::endl;
}

Animal &Animal::operator=(const Animal &src){
	std::cout << COLORA << "Operator Animal " << this->type << " = " << RESET << src.type << std::endl;
	this->type = src.type;
	return *this;
}

std::string Animal::getType(void) const{
	return type;
}

// void	Animal::makeSound(void) const{
// 	std::cout << COLORA << "Grrrrr !" << std::endl;
// }