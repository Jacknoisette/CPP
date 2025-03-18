/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 09:48:47 by codespace         #+#    #+#             */
/*   Updated: 2025/03/18 14:23:32 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

#ifndef COLOR
	#define COLOR "\033[1;33m"
#endif
#define RESET "\033[0m"

class Cat : virtual public Animal{
	protected :
		std::string	type;
	private :
		Brain*	brain;
	public :
		Cat(void);
		~Cat(void);
		Cat(const Cat &copy);
		Cat &operator=(const Cat &src);
		std::string getType(void) const;
		void	makeSound(void) const;
};

#endif