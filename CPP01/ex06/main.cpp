/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 10:25:21 by jdhallen          #+#    #+#             */
/*   Updated: 2025/03/21 10:44:12 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv)
{
	std::string	level;
	Harl		harl;
	
	if (argc == 1)
		return (-1);
	if (argc >= 2) {
		level = argv[1];
		harl.complain(level);
	}
	return (1);
}
