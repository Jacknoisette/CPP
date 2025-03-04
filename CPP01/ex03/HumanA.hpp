/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 13:49:11 by codespace         #+#    #+#             */
/*   Updated: 2025/03/04 10:28:07 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Weapon.hpp"

class	HumanA
{
	private :
		std::string	_name;
		Weapon&		_weapon;
	public :
		HumanA(std::string name , Weapon& weapon);
		~HumanA(void);
		void	attack(void);
};