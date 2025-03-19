/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 13:45:04 by jdhallen          #+#    #+#             */
/*   Updated: 2025/03/19 11:23:45 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void): ClapTrap("_clap_name") ,ScavTrap(), FragTrap(), name("Random DiamondTrap"){
	hitPoint = FragTrap::hitPoint;
	energyPoint =  ScavTrap::energyPoint;
	attackDamage =  FragTrap::attackDamage;
	guardmode = ScavTrap::guardmode;
	std::cout << "Construction of DiamondTrap " << name << ". It does not look natural" << std::endl;
}

DiamondTrap::DiamondTrap(std::string _name): ClapTrap(_name + "_clap_name") ,ScavTrap(_name), FragTrap(_name){
	name = _name;
	hitPoint = FragTrap::hitPoint;
	energyPoint =  ScavTrap::energyPoint;
	attackDamage =  FragTrap::attackDamage;
	guardmode = ScavTrap::guardmode;
	std::cout << "Construction of DiamondTrap " << name << ". It does not look natural" << std::endl;
}

DiamondTrap::~DiamondTrap(void){
	std::cout << "Destruction of DiamondTrap " << name << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy): ClapTrap(copy), ScavTrap(copy), FragTrap(copy){
	*this = copy;
	std::cout << "Construction of DiamondTrap copy " << this->name << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &src){
	std::cout << "Operator DiamondTrap " << this->name << " = " << src.name << std::endl;
	this->name = src.name;
	this->hitPoint = src.hitPoint;
	this->energyPoint = src.energyPoint;
	this->attackDamage = src.attackDamage;
	this->guardmode = src.guardmode;
	return *this;
}

void DiamondTrap::whoAmI(void){
	if (hitPoint > 0)
	{
		std::cout << "A DiamondTrap ask himself if he is " << name << " or " << ClapTrap::name << std::endl;
		hitPoint += 1;
	}
	else if (hitPoint <= 0)
		std::cout << "DiamondTrap " << name << " is dead he is not able to ask himself question" << std::endl;
}