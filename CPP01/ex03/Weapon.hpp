/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 13:50:11 by codespace         #+#    #+#             */
/*   Updated: 2025/03/03 14:47:42 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>

class	Weapon
{
	private :
		std::string _type;

	public :
		Weapon(std::string type = "Stick");
		~Weapon(void);
		std::string	getType(void)	const;
		void	setType(std::string value);
};

#endif