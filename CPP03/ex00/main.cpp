/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 09:37:50 by jdhallen          #+#    #+#             */
/*   Updated: 2025/03/12 11:34:50 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap Johny("Johny");
	ClapTrap Toby("Toby");
	
	Johny.attack("Other ClapTrap");
	Johny.takeDamage(1);
	Johny.attack("Other ClapTrap");
	Johny.attack("Other ClapTrap");
	Johny.attack("Other ClapTrap");
	for (int repaired = 0; repaired < 7 ; repaired++)
		Johny.beRepaired(1);
	Johny.attack("Other ClapTrap");
	for (int takedamage = 0; takedamage < 17 ; takedamage++)
		Johny.takeDamage(1);
	Toby.attack("Other ClapTrap");
	Toby.takeDamage(100);
	return (0);	
}