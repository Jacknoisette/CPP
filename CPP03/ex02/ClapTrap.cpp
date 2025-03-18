/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 09:26:22 by jdhallen          #+#    #+#             */
/*   Updated: 2025/03/14 09:37:43 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void): name("Random ClapTrap"), hitPoint(10), energyPoint(10), attackDamage(0){
	std::cout << "Construction of ClapTrap " << name << std::endl;
}

ClapTrap::ClapTrap(std::string _name): name(_name), hitPoint(10), energyPoint(10), attackDamage(0){
	std::cout << "Construction of ClapTrap " << name << std::endl;
}

ClapTrap::~ClapTrap(void){
	std::cout << "Destruction of ClapTrap " << name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy){
	*this = copy;
	std::cout << "Construction of ClapTrap copy " << this->name << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &src){
	std::cout << "Operator ClapTrap " << this->name << " = " << src.name << std::endl;
	this->name = src.name;
	this->hitPoint = src.hitPoint;
	this->energyPoint = src.energyPoint;
	this->attackDamage = src.attackDamage;
	return *this;
}


void ClapTrap::attack(const std::string& target){
	if (energyPoint > 0 && hitPoint > 0)
	{
		energyPoint -= 1;
		std::cout << "ClapTrap " << name << " attacks " << target;
		std::cout << ", causing " << attackDamage << " points of damage !";
		if (attackDamage <= 0)
			std::cout << " This attack is useless !";
		std::cout << std::endl;
	}
	if (energyPoint <= 0)
		std::cout << "ClapTrap " << name << " have low energy he can't attack" << std::endl;
	if (hitPoint <= 0)
		std::cout << "ClapTrap " << name << " seems dead" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount){
	if (hitPoint <= 0)
	{
		std::cout << "ClapTrap " << name << " was already dead but he still lose " << amount << "HP !";
		std::cout << " Why do you want do hurt him so bad ?" << std::endl;
	}
	else if ((hitPoint * 2) <= (int)amount)
	{
		std::cout << "ClapTrap " << name << " lost a huge amount of " << amount << "HP !";
		std::cout << " You maybe have gone a bit hard on him !" << std::endl;
	}
	else if (hitPoint - amount <= 0)
	{
		std::cout << "ClapTrap " << name << " lost " << amount << "HP !";
		std::cout << " Sadly this attack is fatal for him, he won't survive" << std::endl;
	}
	else
		std::cout << "ClapTrap " << name << " lost " << amount << "HP !" << std::endl;
	hitPoint -= amount;
}

void ClapTrap::beRepaired(unsigned int amount){
	if (energyPoint > 0 && hitPoint > 0)
	{
		hitPoint += amount;
		energyPoint -= 1;
		std::cout << "ClapTrap " << name << " repaired himself and gain " << amount << "HP !" << std::endl;
	}
	else if (hitPoint <= 0)
		std::cout << "ClapTrap " << name << " is dead he can't repaired" << std::endl;
	else if (energyPoint <= 0)
		std::cout << "ClapTrap " << name << " have low energy he can't repaired" << std::endl;
}