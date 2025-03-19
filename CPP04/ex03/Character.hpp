/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 15:36:45 by codespace         #+#    #+#             */
/*   Updated: 2025/03/19 12:47:25 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include <iostream>
#include "ICharacter.hpp"

class Character: public ICharacter{
	private :
		std::string name;
		AMateria* inventory[4];
	public:
		Character(void);
		Character(std::string _name);
		Character(const Character &copy);
		Character &operator=(const Character &src);
		~Character(void);
		std::string const & getName() const;
		
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};


#endif