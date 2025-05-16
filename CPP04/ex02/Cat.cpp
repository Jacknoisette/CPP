/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 09:44:12 by codespace         #+#    #+#             */
/*   Updated: 2025/05/16 11:06:02 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void): AAnimal("Cat"), brain(new Brain){
	std::cout << COLOR << "A " << type << " have spawn !" << RESET << std::endl;	
}
		
Cat::~Cat(void){
	delete brain;
	std::cout << COLOR << "A " << type << " have despawn !" << RESET << std::endl;
}

Cat::Cat(const Cat &copy): AAnimal("Cat"){
	brain = new Brain(*copy.brain);
	*this = copy;
	std::cout << COLOR << "Construction of Cat copy " << this->type << RESET << std::endl;
}

Cat	&Cat::operator=(const Cat &src){
	std::cout << COLOR << "Operator Cat " << this->type << " = " << src.type << RESET << std::endl;
	if (this != &src)
	{
		if (brain)
			delete brain;
		brain = new Brain(*src.brain);
		this->type = src.type;
	}
	return *this;
}

void	Cat::makeSound(void) const{
	std::cout << COLOR << "Meow !" << RESET << std::endl;
}

Brain	*Cat::getBrain(void) const{
	return brain;
}