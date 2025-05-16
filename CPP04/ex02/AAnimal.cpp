/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:52:25 by jdhallen          #+#    #+#             */
/*   Updated: 2025/05/07 15:52:26 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(void): type("Unknown type"){
	std::cout << COLORA << "An Animal " << type << " have spawn !" << RESET << std::endl;	
}

AAnimal::AAnimal(std::string _type): type(_type){
	std::cout << COLORA << "An Animal " << type << " have spawn !" << RESET << std::endl;	
}
		
AAnimal::~AAnimal(void){
	std::cout << COLORA << "An Animal " << type << " have despawn !" << RESET << std::endl;
}

AAnimal::AAnimal(const AAnimal &copy){
	*this = copy;
	std::cout << COLORA << "Construction of Animal copy " << this->type << RESET << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &src){
	std::cout << COLORA << "Operator Animal " << this->type << " = " << RESET << src.type << std::endl;
	this->type = src.type;
	return *this;
}

std::string AAnimal::getType(void) const{
	return type;
}

// void	AAnimal::makeSound(void) const{
// 	std::cout << COLORA << "Grrrrr !" << std::endl;
// }