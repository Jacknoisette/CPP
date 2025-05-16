/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 15:04:25 by codespace         #+#    #+#             */
/*   Updated: 2025/05/15 15:34:00 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"

class ICharacter;

class AMateria{
	protected:
		std::string	type;
	public:
		AMateria(void);
		AMateria(std::string const & _type);
		AMateria(const AMateria &copy);
		virtual ~AMateria();
		AMateria &operator=(const AMateria &src);
		std::string const & getType() const;
		
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& _target);
};


#endif