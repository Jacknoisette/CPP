/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 13:49:29 by codespace         #+#    #+#             */
/*   Updated: 2025/03/20 15:12:04 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Weapon.hpp"

class	HumanB
{
	private :
		std::string	name;
		Weapon		*weapon;
	public :
		HumanB(void);
		HumanB(std::string _name);
		~HumanB(void);
		void	setWeapon(Weapon& _weapon);
		void	attack(void);
};