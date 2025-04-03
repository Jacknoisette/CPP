/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 13:49:48 by codespace         #+#    #+#             */
/*   Updated: 2025/04/03 11:05:49 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(void) : type("Stick"){
}

Weapon::Weapon(std::string _type) : type(_type){
}

Weapon::~Weapon(void){
}

const std::string	Weapon::getType(void) const{
	return type;
}

void	Weapon::setType(std::string value){
	type = value;
}