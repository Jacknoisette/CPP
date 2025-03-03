/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 10:23:23 by codespace         #+#    #+#             */
/*   Updated: 2025/03/03 13:00:22 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#pragma once
#ifndef ZOMBIE_H
# define ZOMBIE_H

class   Zombie{

    private :
        std::string _name;
        
    public :
        Zombie(std::string name = "Foo");
        ~Zombie(void);

        void announce(void) const;
        
};

Zombie* newZombie(std::string name);
Zombie* zombieHorde(int N, std::string name);


#endif