/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 10:50:16 by codespace         #+#    #+#             */
/*   Updated: 2025/03/18 10:50:34 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal{
	protected :
		std::string	type;
	public :
		WrongAnimal(void);	
		WrongAnimal(std::string _type);
		~WrongAnimal(void);
		WrongAnimal(const WrongAnimal &copy);
		WrongAnimal &operator=(const WrongAnimal &src);
		std::string getType(void) const;
		void	makeSound(void) const;
};

#endif