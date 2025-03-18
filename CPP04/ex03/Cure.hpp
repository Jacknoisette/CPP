/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 15:04:25 by codespace         #+#    #+#             */
/*   Updated: 2025/03/18 15:55:23 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

#include <iostream>
#include "AMateria.hpp"

#ifndef COLOR
	#define COLOR "\033[1;32m"
#endif
#define RESET "\033[0m"

class Cure : AMateria{
	public :
		Cure(void);
		virtual ~Cure();
		Cure &operator=(const Cure &src);
		std::string const & getType() const;
		
		virtual AMateria* clone() const;
		virtual void use(ICharacter& _target);
};

#endif