/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 13:45:45 by jdhallen          #+#    #+#             */
/*   Updated: 2025/03/12 13:45:46 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string _name): ClapTrap(_name){
	hitPoint = 100;
	energyPoint = 100;
	attackDamage = 30;
	std::cout << "Construction of FragTrap " << name << ". Looking for someone to high five" << std::endl;
}

FragTrap::~FragTrap(void){
	std::cout << "Destruction of FragTrap " << name << std::endl;
}

void FragTrap::highFivesGuys(void){
	if (energyPoint > 0 && hitPoint > 0)
	{
		std::cout << "FragTrap " << name << " hightFives someone. The hapiness he receives repaired him of 1HP" << std::endl;
		hitPoint += 1;
	}
	else if (hitPoint <= 0)
		std::cout << "FragTrap " << name << " is dead he can't high five" << std::endl;
	else if (energyPoint <= 0)
		std::cout << "FragTrap " << name << " is to tired to high five" << std::endl;
}


// void FragTrap::attack(const std::string& target){
// 	if (energyPoint > 0 && hitPoint > 0)
// 	{
// 		energyPoint -= 1;
// 		std::cout << "FragTrap " << name << " attack " << target;
// 		std::cout << ", causing " << attackDamage << " points of damage ! Because it refused to high five";
// 		if (attackDamage <= 0)
// 			std::cout << " This attack is useless !";
// 		std::cout << std::endl;
// 	}
// 	if (hitPoint <= 0)
// 		std::cout << "FragTrap " << name << " seems dead" << std::endl;
// 	else if (energyPoint <= 0)
// 		std::cout << "FragTrap " << name << " have low energy he want to rest" << std::endl;
// }