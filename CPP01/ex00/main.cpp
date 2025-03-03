/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 10:23:20 by codespace         #+#    #+#             */
/*   Updated: 2025/03/03 15:23:11 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    Zombie* heapZombie;
    
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