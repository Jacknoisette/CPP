/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 09:44:30 by codespace         #+#    #+#             */
/*   Updated: 2025/03/18 11:06:23 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta1 = new Animal();
	const Animal* j1 = new Dog();
	const Animal* i1 = new Cat();
	const WrongAnimal* meta2 = new WrongAnimal();
	const WrongAnimal* i2 = new WrongCat();
	
	std::cout << meta1->getType() << " " << std::endl;
	std::cout << j1->getType() << " " << std::endl;
	std::cout << i1->getType() << " " << std::endl;
	std::cout << meta2->getType() << " " << std::endl;
	std::cout << i2->getType() << " " << std::endl;
	meta1->makeSound(); //will output the animal sound!
	j1->makeSound(); //will output the dog sound!
	i1->makeSound(); //will output the cat sound!
	meta2->makeSound(); //will output the wronganimal sound!
	i2->makeSound(); //will output the wrongcat sound!
	delete(meta1);
	delete(meta2);
	delete(j1);
	delete(i1);
	delete(i2);
	return 0;
}