/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:31:57 by jdhallen          #+#    #+#             */
/*   Updated: 2025/03/20 15:31:58 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

// int	main(int argc, char **argv)
// {
// 	std::string	level;
// 	Harl		harl;
// 	int			i = 1;
	
// 	if (argc == i)
// 		return (-1);
// 	i = 2;
// 	while (argc >= i) {
// 		level = argv[i - 1];
// 		harl.complain(level);
// 		i++;
// 		std::cout << std::endl;
// 	}
// 	return (1);
// }

#include <cstdlib>

int getRandomNumber(int min, int max) {
	return min + (std::rand() % (max - min + 1));
}

int main() {
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR", "INVALID"};
	Harl harl;
	int	r;

	for (int i = 0; i < 30; i++) {
		r = getRandomNumber(0,4);
   		std::cout << "[ " << levels[r] << " ]" << std::endl;
		harl.complain(levels[r]);
		std::cout << std::endl;
	}
	return 0;
}