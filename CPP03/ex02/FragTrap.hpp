/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 13:45:39 by jdhallen          #+#    #+#             */
/*   Updated: 2025/03/13 10:35:41 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public :
		FragTrap(void);
		FragTrap(std::string _name);
		~FragTrap(void);
		FragTrap(const FragTrap &copy);
		FragTrap &operator=(const FragTrap &src);
		void highFivesGuys(void);
};

#endif