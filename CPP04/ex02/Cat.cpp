/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 09:44:12 by codespace         #+#    #+#             */
/*   Updated: 2025/03/18 14:21:48 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void): Animal("Cat"), type("Cat"), brain(new Brain){
	std::cout << COLOR << "A " << type << " have spawn !" << RESET << std::endl;	
}
		
Cat::~Cat(void){
	delete brain;
	std::cout << COLOR << "A " << type << " have despawn !" << RESET << std::endl;
}

Cat::Cat(const Cat &copy): Animal("Cat"){
	brain = new Brain(*copy.brain);
	*this = copy;
	std::cout << COLOR << "Construction of Cat copy " << this->type << RESET << std::endl;
}

Cat	&Cat::operator=(const Cat &src){
	std::cout << COLOR << "Operator Cat " << this->type << " = " << src.type << RESET << std::endl;
	*brain = *src.brain;
	this->type = src.type;
	return *this;
}

std::string Cat::getType(void) const{
	return type;
}

void	Cat::makeSound(void) const{
	std::cout << COLOR << "Meow !" << RESET << std::endl;
}