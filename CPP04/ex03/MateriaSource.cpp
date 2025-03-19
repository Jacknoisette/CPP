/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 15:07:27 by codespace         #+#    #+#             */
/*   Updated: 2025/03/19 15:26:54 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(){
	for (int i = 0; i < 4; i++)
		knowledge[i] = NULL;
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; i++)
		delete knowledge[i];
}

MateriaSource::MateriaSource(const MateriaSource &copy){
	*this = copy;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &src){
	if (this != &src){
		for (int i = 0; i < 4; i++)
			delete knowledge[i];
		for (int i = 0; i < 4; i++)
			if (src.knowledge[i])
				this->knowledge[i] = src.knowledge[i]->clone();
			else
				knowledge[i] = NULL;
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria *m){
	for (int i = 0; i < 4; i++) {
		if (knowledge[i] == NULL) {
			knowledge[i]= m->clone();
			delete m;
			return;
		}
	}
	delete m;
	std::cout << "MateriaSource is full, cannot learn new materia." << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type){
	for (int i = 0; i < 4; i++) {
		if (knowledge[i] && knowledge[i]->getType() == type) {
			return knowledge[i]->clone();
		}
	}
	std::cout << "The MateriaSource don't know this Materia" << std::endl;
	return 0;
}
