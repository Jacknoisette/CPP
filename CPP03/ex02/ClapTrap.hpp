/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 10:33:01 by codespace         #+#    #+#             */
/*   Updated: 2025/05/06 10:26:35 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
	protected :
		std::string	name;
		int			hitPoint;
		int			energyPoint;
		int			attackDamage;
	public :
		ClapTrap(void);
		ClapTrap(std::string _name);
		ClapTrap(const ClapTrap &copy);
		ClapTrap &operator=(const ClapTrap &src);
		virtual ~ClapTrap(void);
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif