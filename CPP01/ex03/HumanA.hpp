/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 13:49:11 by codespace         #+#    #+#             */
/*   Updated: 2025/04/03 11:02:49 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <iostream>
# include "Weapon.hpp"

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

#endif