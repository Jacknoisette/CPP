/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 09:48:47 by codespace         #+#    #+#             */
/*   Updated: 2025/05/07 15:51:57 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include <iostream>
#include "AAnimal.hpp"
#include "Brain.hpp"

#ifndef COLOR
	#define COLOR "\033[1;33m"
#endif
#define RESET "\033[0m"

class Cat : public AAnimal{
	private :
		Brain*	brain;
	public :
		Cat(void);
		~Cat(void);
		Cat(const Cat &copy);
		Cat &operator=(const Cat &src);
		Brain	*getBrain(void) const;
		void	makeSound(void) const;
};

#endif