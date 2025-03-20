/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 14:51:06 by jdhallen          #+#    #+#             */
/*   Updated: 2025/03/20 15:14:21 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#pragma once
#ifndef ZOMBIE_H
# define ZOMBIE_H

class   Zombie{

	private :
		std::string name;
	public :
		Zombie(void);
		Zombie(std::string _name);
		~Zombie(void);

		void announce(void) const;
		
};

Zombie* newZombie(std::string name);
void	randomChump(std::string name);

#endif