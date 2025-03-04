/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 10:25:05 by jdhallen          #+#    #+#             */
/*   Updated: 2025/03/04 12:41:47 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	Harl::debug(void){
	std::cout << "I love having extra bacon for ";
	std::cout << "my 7XL-double-cheese-triple-pickle-special-" << std::endl;
	std::cout << "ketchup burger. I really do!" << std::endl;
}

void	Harl::info(void){
	std::cout << "I cannot believe adding extra bacon cost ";
	std::cout <<  "more money. You didn’t put" << std::endl;
	std::cout << "enough bacon in my burger! If you did, ";
	std::cout << "I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning(void){
	std::cout << "I think I deserve to have some extra bacon ";
	std::cout << "for free. I’ve been coming for" << std::endl;
	std::cout << "years, whereas you started ";
	std::cout << "working here just last month." << std::endl;
}

void	Harl::error(void){
	std::cout << "This is unacceptable! ";
	std::cout << "I want to speak to the manager now." << std::endl;
}
		
void	Harl::complain(std::string level){
	std::string modes[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*func[])() = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	for (int i = 0; i < 4; i++)
		if (level == modes[i])
			(this->*func[i])();
}