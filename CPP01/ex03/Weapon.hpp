/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 13:50:11 by codespace         #+#    #+#             */
/*   Updated: 2025/04/03 11:05:53 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>

class	Weapon
{
	private :
		std::string type;

	public :
		Weapon(void);
		Weapon(std::string _type);
		~Weapon(void);
		
		const std::string	getType(void)	const;
		void		setType(std::string _value);
};

#endif