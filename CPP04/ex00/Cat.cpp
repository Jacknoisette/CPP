/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 09:44:12 by codespace         #+#    #+#             */
/*   Updated: 2025/05/07 11:47:03 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void): Animal("Cat"){
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

void	Cat::makeSound(void) const{
	std::cout << "Meow !" << std::endl;
}