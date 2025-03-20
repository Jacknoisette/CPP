/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 10:22:26 by codespace         #+#    #+#             */
/*   Updated: 2025/03/20 13:42:40 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	_name = name;
	std::cout << _name << " has ☠️  \033[32mSPAWNED\033[0m" << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << _name << " has 🪦 \033[32mDIED\033[0m" << std::endl;
}

void Zombie::announce(void) const
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(std::string name){
	_name = name;
}