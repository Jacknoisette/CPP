/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:08:11 by codespace         #+#    #+#             */
/*   Updated: 2025/05/16 11:25:58 by jdhallen         ###   ########.fr       */
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
	Dog	dog;
	Dog dogCopy(dog);

	for (int i = 0; i < 10; i++)
		dog.getBrain()->setIdea(i, "\033[32mrandomIdeas\033[0m");
	std::cout << "Dog memory" << std::endl;
	for (int i = 0; i < 10; i++)
		dog.getBrain()->displayIdea(i);
	std::cout << "DogCpy memory" << std::endl;
	for (int i = 0; i < 10; i++)
		dogCopy.getBrain()->displayIdea(i);
	dogCopy = dog;
	std::cout << "After =, Dog memory" << std::endl;
	for (int i = 0; i < 10; i++)
		dog.getBrain()->displayIdea(i);
	std::cout << "After =, DogCpy memory" << std::endl;
	for (int i = 0; i < 10; i++)
		dogCopy.getBrain()->displayIdea(i);
	for (int i = 0; i < 10; i++)
		dogCopy.getBrain()->setIdea(i, "\033[30mhello\033[0m");
	std::cout << "After modification, Dog memory" << std::endl;
	for (int i = 0; i < 10; i++)
		dog.getBrain()->displayIdea(i);
	std::cout << "After modification, DogCpy memory" << std::endl;
	for (int i = 0; i < 10; i++)
		dogCopy.getBrain()->displayIdea(i);
	return 0;
}