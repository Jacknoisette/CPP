/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 09:44:58 by codespace         #+#    #+#             */
/*   Updated: 2025/03/18 10:58:19 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include <iostream>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal{
	protected :
		std::string	type;
	public :
        WrongCat(void);
		~WrongCat(void);
		WrongCat(const WrongCat &copy);
		WrongCat &operator=(const WrongCat &src);
		std::string getType(void) const;
		void	makeSound(void) const;
};

#endif