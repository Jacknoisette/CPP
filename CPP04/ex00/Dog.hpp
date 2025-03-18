/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 10:10:40 by codespace         #+#    #+#             */
/*   Updated: 2025/03/18 10:31:52 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include <iostream>
#include "Animal.hpp"

class Dog : virtual public Animal{
	protected :
		std::string	type;
	public :
		Dog(void);
		~Dog(void);
		Dog(const Dog &copy);
		Dog &operator=(const Dog &src);
        std::string getType(void) const;
		void	makeSound(void) const;
};


#endif