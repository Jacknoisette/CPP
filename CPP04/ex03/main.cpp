/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 16:35:50 by jdhallen          #+#    #+#             */
/*   Updated: 2025/03/19 16:54:26 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include "ICharacter.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

void testBasicUsage() {
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
}

void testInventoryOverflow() {
	std::cout << "===== Test Inventory Overflow =====" << std::endl;
	ICharacter* me = new Character("Overflow");

	AMateria* m1 = new Ice();
	AMateria* m2 = new Cure();
	AMateria* m3 = new Ice();
	AMateria* m4 = new Cure();
	AMateria* m5 = new Ice();
	
	me->equip(m1);
	me->equip(m2);
	me->equip(m3);
	me->equip(m4);
	me->equip(m5);

	ICharacter* target = new Character("Target");
	for (int i = 0; i < 5; i++) {
		me->use(i, *target);
	}

	delete m5;
	delete target;
	delete me;
	std::cout << std::endl;
}

void testUnequip() {
	std::cout << "===== Test Unequip =====" << std::endl;
	ICharacter* me = new Character("UnequipTest");
	AMateria* m1 = new Ice();
	me->equip(m1);
	me->unequip(0);

	ICharacter* target = new Character("Target");
	me->use(0, *target);
	me->unequip(10);
	me->use(10, *target);

	delete m1;
	delete target;
	delete me;
	std::cout << std::endl;
}

void testDeepCopy() {
	std::cout << "===== Test Deep Copy =====" << std::endl;
	Character* original = new Character("Original");
	original->equip(new Ice());
	original->equip(new Cure());

	Character* copy = new Character(*original);

	ICharacter* target = new Character("Target");
	std::cout << "Original uses:" << std::endl;
	for (int i = 0; i < 4; i++) {
		original->use(i, *target);
	}
	std::cout << "Copy uses:" << std::endl;
	for (int i = 0; i < 4; i++) {
		copy->use(i, *target);
	}

	delete target;
	delete original;
	delete copy;
	std::cout << std::endl;
}

void testMateriaSourceOverflow() {
	std::cout << "===== Test MateriaSource Overflow =====" << std::endl;
	IMateriaSource* source = new MateriaSource();

	source->learnMateria(new Ice());
	source->learnMateria(new Cure());
	source->learnMateria(new Ice());
	source->learnMateria(new Cure());
	source->learnMateria(new Ice());

	AMateria* unknown = source->createMateria("unknown");
	if (!unknown)
		std::cout << "La création d'une materia inconnue renvoie nullptr comme attendu." << std::endl;
	else
		delete unknown;

	delete source;
	std::cout << std::endl;
}

void testAssignmentOperator() {
	std::cout << "===== Test Assignment Operator =====" << std::endl;

	Character a("Alice");
	AMateria* ice = new Ice(); 
	a.equip(ice);
	a.equip(new Cure());

	Character b("Bob");
	b = a;

	ICharacter* target = new Character("Target");
		
	std::cout << "Alice uses:" << std::endl;
	for (int i = 0; i < 4; i++) {
		a.use(i, *target);
	}
		
	std::cout << "Bob uses:" << std::endl;
	for (int i = 0; i < 4; i++) {
		b.use(i, *target);
	}

    a.unequip(0);
    a.equip(new Ice());
    delete ice;

	std::cout << "After modification:" << std::endl;
	std::cout << "Alice uses:" << std::endl;
	for (int i = 0; i < 4; i++) {
		a.use(i, *target);
	}
		
	std::cout << "Bob uses (should be unchanged):" << std::endl;
	for (int i = 0; i < 4; i++) {
		b.use(i, *target);
	}
		
	delete target;
	std::cout << std::endl;
}

void testMateriaTypeCreation() {
	std::cout << "===== Test Materia Type Creation =====" << std::endl;

	AMateria* ice = new Ice();
	AMateria* cure = new Cure();
	std::cout << "Ice type: " << ice->getType() << std::endl;
	std::cout << "Cure type: " << cure->getType() << std::endl;
	delete ice;
	delete cure;

	IMateriaSource* source = new MateriaSource();
	source->learnMateria(new Ice());
	source->learnMateria(new Cure());
		
	AMateria* m1 = source->createMateria("ice");
	if (m1)
		std::cout << "Created Materia type: " << m1->getType() << std::endl;
	else
		std::cout << "Error: Failed to create Materia of type 'ice'" << std::endl;

	AMateria* unknown = source->createMateria("thunder");
	if (!unknown)
		std::cout << "Unknown Materia type correctly returns NULL" << std::endl;
	else {
		std::cout << "Error: Unknown Materia type did not return NULL" << std::endl;
		delete unknown;
	}
		
	delete m1;
	delete source;
	std::cout << std::endl;
}

void testMateriaSourceAssignment() {
	std::cout << "===== Test MateriaSource Assignment =====" << std::endl;
		
	MateriaSource src;
	src.learnMateria(new Ice());
	src.learnMateria(new Cure());
		
	MateriaSource copy;
	copy = src;

	AMateria* m1 = src.createMateria("ice");
	AMateria* m2 = copy.createMateria("ice");
		
	if (m1 && m2) {
		std::cout << "Original Materia type: " << m1->getType() << std::endl;
		std::cout << "Copied Materia type: " << m2->getType() << std::endl;
	}
	else {
		std::cout << "Error: Echec dans la création d'une Materia à partir d'une des sources" << std::endl;
	}
		
	delete m1;
	delete m2;
	std::cout << std::endl;
}

int main()
{
	testBasicUsage();
	testInventoryOverflow();
	testUnequip();
	testDeepCopy();
	testMateriaSourceOverflow();
	testAssignmentOperator();
	testMateriaTypeCreation();
	testMateriaSourceAssignment();	
	return 0;
}

// std::cout << "\033[35;1;5mtest" << "\033[0m" << std::endl;