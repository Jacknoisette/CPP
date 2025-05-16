/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 10:50:16 by codespace         #+#    #+#             */
/*   Updated: 2025/05/07 12:07:00 by jdhallen         ###   ########.fr       */
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
		virtual ~WrongAnimal(void);
		WrongAnimal(const WrongAnimal &copy);
		WrongAnimal &operator=(const WrongAnimal &src);
		std::string getType(void) const;
		void	makeSound(void) const;
};

#endif