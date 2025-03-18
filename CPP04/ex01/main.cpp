/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:08:11 by codespace         #+#    #+#             */
/*   Updated: 2025/03/18 14:27:13 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
	int nbr = 10;
	nbr = (nbr % 2) ? nbr - 1 : nbr;
	Animal* animals[nbr];
	
	for (int i = 0; i < nbr; ++i) {
		if (i < (nbr / 2))	
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}
	for (int i = 0; i < nbr; ++i) {
		delete animals[i];
	}
	return 0;
}