/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 13:50:11 by codespace         #+#    #+#             */
/*   Updated: 2025/03/04 10:28:46 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

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