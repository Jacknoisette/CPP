/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 15:20:09 by codespace         #+#    #+#             */
/*   Updated: 2025/05/07 16:08:07 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void): name("Random Guy"){
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
}

Character::Character(std::string _name): name(_name){
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
}

Character::Character(const Character &copy){
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
	*this = copy;
}

Character &Character::operator=(const Character &src){
	if (this != &src){
		for (int i = 0; i < 4; i++){
			if (inventory[i])
				delete inventory[i];
			if (src.inventory[i])
				this->inventory[i] = src.inventory[i]->clone();
			else
				inventory[i] = NULL;
		}
		this->name = src.name;
	}
	return *this;
}

Character::~Character(){
	for (int i = 0; i < 4; i++)
		delete inventory[i];
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
	if (idx >= 0 && idx < 4)
		inventory[idx] = NULL;
	else
		std::cout << "Invalid Index" << std::endl;
}

void Character::use(int idx, ICharacter& target){
	if (idx >= 0 && idx < 4){
		if (inventory[idx])
			inventory[idx]->use(target);
		else
			std::cout << "Inventory Slot is empty" << std::endl;
	}
	else
		std::cout << "Invalid Index" << std::endl;
}