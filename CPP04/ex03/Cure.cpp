/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 15:03:50 by codespace         #+#    #+#             */
/*   Updated: 2025/03/18 16:00:11 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void) : AMateria("Cure"){}

Cure::~Cure(){}

Cure	&Cure::operator=(const Cure &src){
    this->type = src.type;
	return *this;
}

std::string const & Cure::getType() const{
    
}

AMateria* Cure::clone() const{
	return new Cure();
}

void Cure::use(ICharacter& _target){
    std::cout << "* heals " << _target.getName() << "'s wounds *" << std::endl;
}

