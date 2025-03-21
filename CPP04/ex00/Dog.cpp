/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 10:11:52 by codespace         #+#    #+#             */
/*   Updated: 2025/03/18 10:35:38 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void): Animal("Dog"), type("Dog"){
	std::cout << "A " << type << " have spawn !" << std::endl;	
}
		
Dog::~Dog(void){
	std::cout << "A " << type << " have despawn !" << std::endl;
}

Dog::Dog(const Dog &copy): Animal("Dog"){
	*this = copy;
	std::cout << "Construction of Dog copy " << this->type << std::endl;
}

Dog	&Dog::operator=(const Dog &src){
	std::cout << "Operator Dog " << this->type << " = " << src.type << std::endl;
	this->type = src.type;
	return *this;
}

std::string Dog::getType(void) const{
	return type;
}

void	Dog::makeSound(void) const{
	std::cout << "Wouf !" << std::endl;
}