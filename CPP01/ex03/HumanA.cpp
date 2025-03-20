/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 13:48:52 by codespace         #+#    #+#             */
/*   Updated: 2025/03/20 15:12:13 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(Weapon& _weapon) : name("Random Guy"), weapon(_weapon){
}

HumanA::HumanA(std::string _name, Weapon& _weapon) : name(_name), weapon(_weapon){
}

HumanA::~HumanA(void){
}

void	HumanA::attack(void){
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}