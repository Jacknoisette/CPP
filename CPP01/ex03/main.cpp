/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 13:49:35 by codespace         #+#    #+#             */
/*   Updated: 2025/03/20 15:17:28 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

int main(void)
{
	{
		Weapon	club = Weapon("crude spiked club");
		HumanA	bob("Bob", club);
		
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon	club = Weapon("crude spiked club");
		HumanB	jim("Jim");
		
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	return 0;
}
