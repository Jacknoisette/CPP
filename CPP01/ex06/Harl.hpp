/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 10:25:10 by jdhallen          #+#    #+#             */
/*   Updated: 2025/04/03 11:43:05 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>

class	Harl{
	private :
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);
	public :
		void	complain(std::string level);
};

#endif