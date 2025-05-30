/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 15:03:50 by codespace         #+#    #+#             */
/*   Updated: 2025/05/07 17:33:55 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(void): type("Unknown type"){
}

AMateria::AMateria(std::string const & _type): type(_type){
}

AMateria::~AMateria(void){
}

AMateria::AMateria(const AMateria &copy){
	*this = copy;
}

AMateria &AMateria::operator=(const AMateria &src){
	(void)src;
	return *this;
}

std::string const & AMateria::getType() const{
	return type;
}

void AMateria::use(ICharacter& _target){
	(void)_target;
	std::cout << "Row Materia can't be used" << std::endl;
}