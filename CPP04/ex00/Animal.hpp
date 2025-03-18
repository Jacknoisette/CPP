/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 09:44:58 by codespace         #+#    #+#             */
/*   Updated: 2025/03/18 11:06:14 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal{
	protected :
		std::string	type;
	public :
		Animal(void);	
		Animal(std::string _type);
		virtual ~Animal(void);
		Animal(const Animal &copy);
		Animal &operator=(const Animal &src);
		virtual std::string getType(void) const;
		virtual void	makeSound(void) const;
};

#endif