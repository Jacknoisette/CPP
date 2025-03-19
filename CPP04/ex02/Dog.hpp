/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 10:10:40 by codespace         #+#    #+#             */
/*   Updated: 2025/03/19 12:50:05 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

#ifndef COLOR
	#define COLOR "\033[1;35m"
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