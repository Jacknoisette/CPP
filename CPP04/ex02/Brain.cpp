/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 13:38:56 by codespace         #+#    #+#             */
/*   Updated: 2025/03/19 10:21:33 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void){
	for (int i = 0; i < 100; ++i)
		ideas[i] = "Empty idea";
	std::cout << COLORB << "A Brain created !" << RESET << std::endl;
}

Brain::Brain(std::string *_ideas){
	for (int i = 0; i < 100; ++i) {
		if (_ideas[i] != (std::string)NULL)
			ideas[i] = _ideas[i];
		else
			ideas[i] = "Empty idea";
	}
	std::cout << COLORB << "A Brain created !" << RESET << std::endl;
}
		
Brain::~Brain(void){
	std::cout << COLORB << "A Brain dead !" << RESET << std::endl;
}

Brain::Brain(const Brain &copy){
	*this = copy;
	std::cout << COLORB << "A Brain is clone !" << RESET << std::endl;
}

Brain &Brain::operator=(const Brain &src){
	std::cout << COLORB << "Operator Brain !" << RESET << std::endl;
	if (this != &src) {
        for (int i = 0; i < 100; ++i) {
            this->ideas[i] = src.ideas[i];
        }
    }
	return *this;
}

std::string Brain::getIdea(int index) const{
	if (index >= 0 && index < 100)
		return ideas[index];
	return "";
}

std::string	*Brain::getMemory(void) const{
	return (std::string	*)ideas;
}

void	Brain::displayIdea(int index) const{
	if (index >= 0 && index < 100)
		std::cout << COLORB << "idea number  : " << index << " " << ideas[index] << RESET << std::endl;
	else
		std::cout << COLORB << "This idea is to big for a Brain" << RESET << std::endl;
}

void	Brain::displayMemory(void) const{
	for (int i = 0; i < 100; ++i)
		displayIdea(i);
}
