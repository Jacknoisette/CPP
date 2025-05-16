/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 15:03:50 by codespace         #+#    #+#             */
/*   Updated: 2025/05/07 17:34:50 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure"){}

Cure::~Cure(){}

Cure::Cure(const Cure &copy){
	*this = copy;
}

Cure	&Cure::operator=(const Cure &src){
    this->type = src.type;
	return *this;
}

std::string const & Cure::getType() const{
    return type;
}

AMateria* Cure::clone() const{
	return new Cure();
}

void Cure::use(ICharacter& _target){
    std::cout << "* heals " << _target.getName() << "'s wounds *" << std::endl;
}

