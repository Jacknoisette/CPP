/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 15:36:45 by codespace         #+#    #+#             */
/*   Updated: 2025/03/18 16:23:57 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include <iostream>
#include "ICharacter.hpp"

class Character: ICharacter{
	private :
		std::string name;
		AMateria* inventory[4];
	public:
		Character(void);
		Character(std::string _name);
		Character(const Character &copy);
		Character &operator=(const Character &src);
		virtual ~Character();
		virtual std::string const & getName() const;
		
		virtual void equip(AMateria* m);
		virtual void unequip(int idx);
		virtual void use(int idx, Character& target);
};


#endif