/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 15:03:50 by codespace         #+#    #+#             */
/*   Updated: 2025/03/18 15:40:51 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(std::string const & _type): type(_type){
}

AMateria::~AMateria(void){
}

std::string const & AMateria::getType() const{
	return type;
}

void AMateria::use(ICharacter& _target){
}