/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 10:10:40 by codespace         #+#    #+#             */
/*   Updated: 2025/03/18 14:23:44 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

#ifndef COLOR
	#define COLOR "\033[1;30m"
#endif
#define RESET "\033[0m"

class Dog : virtual public Animal{
	protected :
		std::string	type;
	private :
		Brain*	brain;
	public :
		Dog(void);
		~Dog(void);
		Dog(const Dog &copy);
		Dog &operator=(const Dog &src);
        std::string getType(void) const;
		void	makeSound(void) const;
};


#endif