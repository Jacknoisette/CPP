/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 15:20:09 by codespace         #+#    #+#             */
/*   Updated: 2025/03/18 16:26:06 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void): name("Random Guy"){
}

Character::Character(std::string _name): name(_name){
}

Character::Character(const Character &copy){
	*this = copy;
}

Character &Character::operator=(const Character &src){
	if (this->name != src.name)
		this->name = src.name;
	return *this;
}

Character::~Character(){
}

std::string const & Character::getName() const{
	return name;
}

void Character::equip(AMateria* m){
	for (int i = 0; i < 4; i++) {
		if (inventory[i] == NULL) {
			inventory[i] = m;
			return;
		}
	}
	std::cout << "Inventory is full, cannot equip the Materia." << std::endl;
}

void Character::unequip(int idx){
	if (idx >= 0 && idx <= 4)
		inventory[idx] = NULL;
	else
		std::cout << "Invalid Index" << std::endl;
}

void Character::use(int idx, Character& target){
	inventory[idx]->use(target);
}