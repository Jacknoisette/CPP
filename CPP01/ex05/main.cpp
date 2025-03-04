/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 10:25:21 by jdhallen          #+#    #+#             */
/*   Updated: 2025/03/04 12:46:42 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv)
{
	std::string	level;
	Harl		harl;
	int			i = 1;
	
	if (argc == i)
		return (-1);
	i = 2;
	while (argc >= i) {
		level = argv[i - 1];
		harl.complain(level);
		i++;
		std::cout << std::endl;
	}
	return (1);
}