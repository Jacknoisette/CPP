/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 10:23:23 by codespace         #+#    #+#             */
/*   Updated: 2025/03/19 10:35:42 by jdhallen         ###   ########.fr       */
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
        void setName(std::string name);
};

Zombie* zombieHorde(int N, std::string name);


#endif