/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 12:59:52 by codespace         #+#    #+#             */
/*   Updated: 2025/03/03 15:23:07 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie*	horde1;
	int		n1 = 10;
	std::cout << "\nApparition d'une horde de " << n1 << " zombie" << std::endl;
	horde1 = zombieHorde(n1, "Zombie");
	if (!horde1)
		return -1;
	for (int i = 0; i < n1; i++)
		horde1[i].announce();
	std::cout << "Et Steve apparut avec une TNT" << std::endl;
	delete[] horde1;

	Zombie*	horde2;
	int		n2 = 100;
	std::cout << "\nApparition d'une horde de " << n2 << " zombie" << std::endl;
	horde2 = zombieHorde(n2, "Zombie");
	if (!horde2)
		return -1;
	for (int i = 0; i < n2; i++)
		horde2[i].announce();
	std::cout << "Et Steve apparut avec un full stuff netherite" << std::endl;
	delete[] horde2;
	return 0;
}