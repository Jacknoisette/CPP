/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 13:49:11 by codespace         #+#    #+#             */
/*   Updated: 2025/03/20 15:11:17 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Weapon.hpp"

class	HumanA
{
	private :
		std::string	name;
		Weapon&		weapon;
	public :
		HumanA(Weapon& _weapon);
		HumanA(std::string _name , Weapon& _weapon);
		~HumanA(void);
		void	attack(void);
};