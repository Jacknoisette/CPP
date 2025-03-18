/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 10:11:52 by codespace         #+#    #+#             */
/*   Updated: 2025/03/18 14:22:49 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void): Animal("Dog"), type("Dog"), brain(new Brain){
	std::cout << COLOR << "A " << type << " have spawn !" << RESET << std::endl;	
}
		
Dog::~Dog(void){
	delete brain;
	std::cout << COLOR << "A " << type << " have despawn !" << RESET << std::endl;
}

Dog::Dog(const Dog &copy): Animal("Dog"){
	brain = new Brain(*copy.brain);
	*this = copy;
	std::cout << COLOR << "Construction of Dog copy " << this->type << RESET << std::endl;
}

Dog	&Dog::operator=(const Dog &src){
	std::cout << COLOR << "Operator Dog " << this->type << " = " << src.type << RESET << std::endl;
	*brain = *src.brain;
	this->type = src.type;
	return *this;
}

std::string Dog::getType(void) const{
	return type;
}

void	Dog::makeSound(void) const{
	std::cout << COLOR << "Wouf !" << RESET << std::endl;
}