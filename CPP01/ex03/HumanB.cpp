/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 13:49:20 by codespace         #+#    #+#             */
/*   Updated: 2025/03/31 11:20:27 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(void): name("Random Guy"), weapon((Weapon *)NULL){
}

HumanB::HumanB(std::string _name):	name(_name), weapon((Weapon *)NULL){
}

HumanB::~HumanB(void){
}

void	HumanB::setWeapon(Weapon& _weapon){
	weapon = &_weapon;
}

void	HumanB::attack(void){
	if (weapon)
		std::cout << name << " attacks with their " << weapon->getType() << std::endl;
	else
		std::cout << name << " attacks with their " << "Fist" << std::endl;
}