/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 09:44:58 by codespace         #+#    #+#             */
/*   Updated: 2025/05/07 11:47:18 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include <iostream>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal{
	public :
        WrongCat(void);
		~WrongCat(void);
		WrongCat(const WrongCat &copy);
		WrongCat &operator=(const WrongCat &src);
		void	makeSound(void) const;
};

#endif