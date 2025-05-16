/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 09:44:30 by codespace         #+#    #+#             */
/*   Updated: 2025/05/07 11:21:35 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "Create Animal :" << std::endl;
	const Animal* baseAnimal = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	const WrongAnimal* wrongAnimal = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();
	
	std::cout << "\nGet type test :" << std::endl;
	std::cout << baseAnimal->getType() << " " << std::endl;
	std::cout << dog->getType() << " " << std::endl;
	std::cout << cat->getType() << " " << std::endl;
	std::cout << wrongAnimal->getType() << " " << std::endl;
	std::cout << wrongCat->getType() << " " << std::endl;
	std::cout << "\nMake sound :" << std::endl;
	baseAnimal->makeSound();
	dog->makeSound();
	cat->makeSound();
	wrongAnimal->makeSound();
	wrongCat->makeSound();
	std::cout << "\nDelete :" << std::endl;
	delete(baseAnimal);
	delete(wrongAnimal);
	delete(dog);
	delete(cat);
	delete(wrongCat);
	return 0;
}