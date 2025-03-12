/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 09:26:22 by jdhallen          #+#    #+#             */
/*   Updated: 2025/03/12 11:52:40 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string _name): ClapTrap(_name){
	hitPoint = 100;
	energyPoint = 50;
	attackDamage = 20;
	std::cout << "Construction of FragTrap " << name << ". He start in patrol mode" << std::endl;
}

FragTrap::~FragTrap(void){
	std::cout << "Destruction of FragTrap " << name << std::endl;
}

void FragTrap::attack(const std::string& target){
	if (energyPoint > 0 && hitPoint > 0)
	{
		energyPoint -= 1;
		std::cout << "FragTrap " << name << " defends the gate and attacks " << target;
		std::cout << ", causing " << attackDamage << " points of damage !";
		if (attackDamage <= 0)
			std::cout << " This attack is useless !";
		std::cout << std::endl;
	}
	if (energyPoint <= 0)
		std::cout << "FragTrap " << name << " have low energy he can't attack while he guards the gate" << std::endl;
	if (hitPoint <= 0)
		std::cout << "FragTrap " << name << " seems dead" << std::endl;
}

void FragTrap::highFivesGuys(void){

}
