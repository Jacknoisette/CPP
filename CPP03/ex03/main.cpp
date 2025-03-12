/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 09:37:50 by jdhallen          #+#    #+#             */
/*   Updated: 2025/03/12 15:07:25 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main(void)
{
	std::cout << "\033[33m";
	ClapTrap Johny("Johny");
	std::cout << "\033[34m";
	ScavTrap Scavy("Scavy");
	std::cout << "\033[36m";
	FragTrap Checker("Checker");
	std::cout << "\033[31m";
	DiamondTrap Grrrrr("Grrrrr");
	std::cout << "\033[0m";
	
	Johny.takeDamage(100);
	Scavy.takeDamage(100);
	Checker.takeDamage(100);
	Grrrrr.takeDamage(70);
	Johny.attack("(Who cares ?)");
	Scavy.attack("(Who cares ?)");
	Checker.attack("(Who cares ?)");
	Grrrrr.attack("(Who cares ?)");
	Johny.beRepaired(100);
	Scavy.beRepaired(100);
	Checker.beRepaired(100);
	Grrrrr.beRepaired(70);
	Scavy.guardGate();
	Grrrrr.guardGate();
	Checker.highFivesGuys();
	Grrrrr.highFivesGuys();
	Grrrrr.whoAmI();
	// std::cout << "\033[31m";
	// Johny.attack("Other ClapTrap");
	// Johny.takeDamage(1);
	// Johny.attack("Other ClapTrap");
	// Johny.attack("Other ClapTrap");
	// Johny.attack("Other ClapTrap");
	// for (int repaired = 0; repaired < 7 ; repaired++)
	// 	Johny.beRepaired(1);
	// Johny.attack("Other ClapTrap");
	// for (int takedamage = 0; takedamage < 17 ; takedamage++)
	// 	Johny.takeDamage(1);
	// std::cout << "\033[36m";
	// Toby.attack("Other ClapTrap");
	// Toby.takeDamage(100);

	// std::cout << "\033[37m";
	// Scavy.attack("Other ClapTrap");
	// Scavy.takeDamage(1);
	// Scavy.guardGate();
	// Scavy.attack("Other ClapTrap");
	// Scavy.attack("Other ClapTrap");
	// Scavy.attack("Other ClapTrap");
	// Scavy.beRepaired(20);
	// Scavy.attack("Other ClapTrap");
	// for (int takedamage = 0; takedamage < 8; takedamage++)
	// 	Scavy.takeDamage(10);
	// Scavy.guardGate();
	// for (int takedamage = 0; takedamage < 17 ; takedamage++)
	// 	Scavy.attack("Other ClapTrap");
	// std::cout << "\033[0m";

	// std::cout << "\033[1m";
	// Checker.attack("Other ClapTrap");
	// Checker.takeDamage(1);
	// Checker.highFivesGuys();
	// Checker.attack("Other ClapTrap");
	// Checker.attack("Other ClapTrap");
	// Checker.attack("Other ClapTrap");
	// Checker.beRepaired(14);
	// Checker.attack("Other ClapTrap");
	// for (int takedamage = 0; takedamage < 8; takedamage++)
	// 	Checker.takeDamage(10);
	// Checker.highFivesGuys();
	// for (int takedamage = 0; takedamage < 17 ; takedamage++)
	// 	Checker.attack("Other ClapTrap");
	// std::cout << "\033[0m";

	// std::cout << "\033[2m";
	// Grrrrr.attack("Other ClapTrap");
	// Grrrrr.takeDamage(1);
	// Grrrrr.highFivesGuys();
	// Grrrrr.guardGate();
	// Grrrrr.attack("Other ClapTrap");
	// Grrrrr.attack("Other ClapTrap");
	// Grrrrr.attack("Other ClapTrap");
	// Grrrrr.beRepaired(14);
	// Grrrrr.attack("Other ClapTrap");
	// for (int takedamage = 0; takedamage < 8; takedamage++)
	// 	Grrrrr.takeDamage(10);
	// Grrrrr.highFivesGuys();
	// Grrrrr.guardGate();
	// Grrrrr.whoAmI();
	// for (int takedamage = 0; takedamage < 17 ; takedamage++)
	// 	Grrrrr.attack("Other ClapTrap");
	// std::cout << "\033[0m";
	return (0);	
}
