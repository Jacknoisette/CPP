/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 13:45:04 by jdhallen          #+#    #+#             */
/*   Updated: 2025/03/12 15:03:32 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string _name): ClapTrap(_name + "_clap_name") ,ScavTrap(_name), FragTrap(_name){
	name = _name;
	hitPoint = FragTrap::hitPoint;
	energyPoint =  ScavTrap::energyPoint;
	attackDamage =  FragTrap::attackDamage;
	std::cout << "Construction of DiamondTrap " << name << ". It does not look natural" << std::endl;
}

DiamondTrap::~DiamondTrap(void){
	std::cout << "Destruction of DiamondTrap " << name << std::endl;
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