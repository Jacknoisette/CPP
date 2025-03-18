/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 09:48:47 by codespace         #+#    #+#             */
/*   Updated: 2025/03/18 10:31:53 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include <iostream>
#include "Animal.hpp"

class Cat : virtual public Animal{
	protected :
		std::string	type;
	public :
		Cat(void);
		~Cat(void);
		Cat(const Cat &copy);
		Cat &operator=(const Cat &src);
		std::string getType(void) const;
		void	makeSound(void) const;
};

#endif