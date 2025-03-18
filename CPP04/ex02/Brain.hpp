/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 13:24:44 by codespace         #+#    #+#             */
/*   Updated: 2025/03/18 14:23:29 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

#define COLORB "\033[1;31m"
#define RESET "\033[0m"

class Brain{
	protected :
		std::string	ideas[100];
	public :
        Brain(void);
        Brain(std::string *_ideas);
		~Brain(void);
		Brain(const Brain &copy);
		Brain &operator=(const Brain &src);
		std::string	getIdea(int index) const;
		std::string	*getMemory(void) const;
		void		displayIdea(int index) const;
		void		displayMemory(void)	const;
};

#endif