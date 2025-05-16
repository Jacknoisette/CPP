/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 15:35:58 by codespace         #+#    #+#             */
/*   Updated: 2025/05/07 17:35:03 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice"){}

Ice::~Ice(){}

Ice::Ice(const Ice &copy){
	*this = copy;
}

Ice	&Ice::operator=(const Ice &src){
    this->type = src.type;
	return *this;
}

std::string const & Ice::getType() const{
    return type;
}

AMateria* Ice::clone() const{
	return new Ice();
}

void Ice::use(ICharacter& _target){
    std::cout << "* shoots an ice bolt at " << _target.getName() << " *" << std::endl;
}