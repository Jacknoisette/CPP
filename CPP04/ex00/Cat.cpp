/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 09:44:12 by codespace         #+#    #+#             */
/*   Updated: 2025/03/18 11:08:09 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void): Animal("Cat"), type("Cat"){
	std::cout << "A " << type << " have spawn !" << std::endl;	
}
		
Cat::~Cat(void){
	std::cout << "A " << type << " have despawn !" << std::endl;
}

Cat::Cat(const Cat &copy): Animal("Cat"){
	*this = copy;
	std::cout << "Construction of Cat copy " << this->type << std::endl;
}

Cat	&Cat::operator=(const Cat &src){
	std::cout << "Operator Cat " << this->type << " = " << src.type << std::endl;
	this->type = src.type;
	return *this;
}

std::string Cat::getType(void) const{
	return type;
}

void	Cat::makeSound(void) const{
	std::cout << "Meow !" << std::endl;
}