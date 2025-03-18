/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 15:04:25 by codespace         #+#    #+#             */
/*   Updated: 2025/03/18 15:54:49 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

#include <iostream>
#include "AMateria.hpp"

#ifndef COLOR
	#define COLOR "\033[1;34m"
#endif
#define RESET "\033[0m"

class Ice : AMateria{
	public :
		Ice(void);
		virtual ~Ice();
		Ice &operator=(const Ice &src);
		std::string const & getType() const;
		
		virtual AMateria* clone() const;
		virtual void use(ICharacter& _target);
};

#endif