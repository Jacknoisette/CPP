/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 10:10:40 by codespace         #+#    #+#             */
/*   Updated: 2025/05/07 11:44:53 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include <iostream>
#include "Animal.hpp"

class Dog : public Animal{
	public :
		Dog(void);
		~Dog(void);
		Dog(const Dog &copy);
		Dog &operator=(const Dog &src);
		void	makeSound(void) const;
};


#endif