/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 15:35:58 by codespace         #+#    #+#             */
/*   Updated: 2025/03/18 15:54:28 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice"){}

Ice::~Ice(){}

Ice	&Ice::operator=(const Ice &src){
    this->type = src.type;
	return *this;
}

std::string const & Ice::getType() const{
    
}

AMateria* Ice::clone() const{
	return new Ice();
}

void Ice::use(ICharacter& _target){
    std::cout << "* shoots an ice bolt at " << _target.getName() << " *" << std::endl;
}