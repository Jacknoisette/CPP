/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:52:21 by jdhallen          #+#    #+#             */
/*   Updated: 2025/05/07 15:52:22 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

#include <iostream>

#define COLORA "\033[1;32m"
#define RESET "\033[0m"

class AAnimal{
	protected :
		std::string	type;
	public :
		AAnimal(void);	
		AAnimal(std::string _type);
		virtual ~AAnimal(void);
		AAnimal(const AAnimal &copy);
		AAnimal &operator=(const AAnimal &src);
		virtual std::string getType(void) const;
		virtual void	makeSound(void) const = 0;
};

#endif