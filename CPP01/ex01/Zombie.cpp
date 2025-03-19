/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 10:22:26 by codespace         #+#    #+#             */
/*   Updated: 2025/03/19 10:36:11 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	_name = name;
}

Zombie::~Zombie(void)
{
	std::cout << _name << ": Brai.ii.iin..zz.Z..." << " has 🪦 \033[32mDIED\033[0m" << std::endl;
}

void	Zombie::announce(void) const
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << " has ☠️ \033[32mSPAWN\033[0m" << std::endl;
}

void	Zombie::setName(std::string name){
	_name = name;
}