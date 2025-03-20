/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 13:50:11 by codespace         #+#    #+#             */
/*   Updated: 2025/03/20 15:16:45 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class	Weapon
{
	private :
		std::string type;

	public :
		Weapon(void);
		Weapon(std::string _type);
		~Weapon(void);
		
		std::string	getType(void)	const;
		void		setType(std::string _value);
};