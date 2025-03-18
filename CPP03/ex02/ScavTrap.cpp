/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 13:45:34 by jdhallen          #+#    #+#             */
/*   Updated: 2025/03/14 09:37:51 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void): ClapTrap(){
	hitPoint = 100;
	energyPoint = 50;
	attackDamage = 20;
	guardmode = false;
	std::cout << "Construction of ScavTrap " << name << ". He start in patrol mode" << std::endl;
}

ScavTrap::ScavTrap(std::string _name): ClapTrap(_name){
	hitPoint = 100;
	energyPoint = 50;
	attackDamage = 20;
	guardmode = false;
	std::cout << "Construction of ScavTrap " << name << ". He start in patrol mode" << std::endl;
}

ScavTrap::~ScavTrap(void){
	std::cout << "Destruction of ScavTrap " << name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy): ClapTrap(copy){
	*this = copy;
	std::cout << "Construction of ScavTrap copy " << this->name << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &src){
	std::cout << "Operator ScavTrap " << this->name << " = " << src.name << std::endl;
	this->name = src.name;
	this->hitPoint = src.hitPoint;
	this->energyPoint = src.energyPoint;
	this->attackDamage = src.attackDamage;
	return *this;
}

void ScavTrap::attack(const std::string& target){
	if (guardmode == true){
		if (energyPoint > 0 && hitPoint > 0)
		{
			energyPoint -= 1;
			std::cout << "ScavTrap " << name << " defends the gate and attacks " << target;
			std::cout << ", causing " << attackDamage << " points of damage !";
			if (attackDamage <= 0)
				std::cout << " This attack is useless !";
			std::cout << std::endl;
		}
		else if (energyPoint <= 0)
			std::cout << "ScavTrap " << name << " have low energy he can't attack while he guards the gate" << std::endl;
		else if (hitPoint <= 0)
			std::cout << "ScavTrap " << name << " seems dead" << std::endl;
	}
	else if (guardmode == false)
	{
		if (energyPoint > 0 && hitPoint > 0)
		{
			energyPoint -= 1;
			std::cout << "ScavTrap " << name << " attacks during patrol " << target;
			std::cout << ", causing " << attackDamage << " points of damage ! This is powerfull";
			if (attackDamage <= 0)
				std::cout << " This attack is useless !";
			std::cout << std::endl;
		}
		else if (hitPoint <= 0)
			std::cout << "ScavTrap " << name << " seems dead" << std::endl;
		else if (energyPoint <= 0)
			std::cout << "ScavTrap " << name << " have low energy he can't attack during patrol" << std::endl;
	}
}

void ScavTrap::guardGate(void){
	if (hitPoint <= 0)
		std::cout << "ScavTrap " << name << " is dead he can't change guard position" << std::endl;
	else if (guardmode == false)
	{
		guardmode = true;
		std::cout << "ScavTrap " << name << " left patrol and is now guarding the gate" << std::endl;
	}
	else if (guardmode == true)
	{
		guardmode = false;
		std::cout << "ScavTrap " << name << " left the gate and is now doing a patrol" << std::endl;
	}
}
