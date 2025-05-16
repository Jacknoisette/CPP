/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 09:48:47 by codespace         #+#    #+#             */
/*   Updated: 2025/05/07 11:44:57 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include <iostream>
#include "Animal.hpp"

class Cat : public Animal{
	public :
		Cat(void);
		~Cat(void);
		Cat(const Cat &copy);
		Cat &operator=(const Cat &src);
		void	makeSound(void) const;
};

#endif