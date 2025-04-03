/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 10:48:35 by jdhallen          #+#    #+#             */
/*   Updated: 2025/04/03 10:48:46 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie	*heapZombie;
		
	std::cout << "\n1er zombie creer avec la HEAP" << std::endl;
	heapZombie = newZombie("Johny");
	if (heapZombie == NULL)
		std::cout << "Échec de l'allocation de mémoire!" << std::endl;
	heapZombie->announce();
	delete heapZombie;
	std::cout << "\n2eme zombie creer avec la STACK" << std::endl;
	randomChump("Robert");
	return 0;
}