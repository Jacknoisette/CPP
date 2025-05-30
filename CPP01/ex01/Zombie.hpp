/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 14:50:45 by jdhallen          #+#    #+#             */
/*   Updated: 2025/04/03 10:53:23 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

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
		void setName(std::string _name);
};

Zombie* zombieHorde(int N, std::string name);

#endif