/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 09:14:44 by codespace         #+#    #+#             */
/*   Updated: 2025/05/22 12:25:54 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base(void){
}

void custom_seed() {
	static unsigned int counter = 8;
	srand((counter - 1) * counter * time(0));
    counter++;
}

Base *generate(int checker){
	(void)checker;
	custom_seed();
	int	rand_nbr = rand() % 3;
	switch (rand_nbr)
	{
		case 0 :
		{
			std::cout << "Generate A : get ";
			return new A();
		}
;		case 1 :
		{
			std::cout << "Generate B : get ";
			return new B();
		}
		case 2 :
		{
			std::cout << "Generate C : get ";
			return new C();
		}
	}
	return NULL;
}

Base *generate(void){
	custom_seed();
	int	rand_nbr = rand() % 3;
	switch (rand_nbr)
	{
		case 0 :
			return new A();
		case 1 :
			return new B();
		case 2 :
			return new C();
	}
	return NULL;
}

void identify(Base* p){
	if (dynamic_cast<A*>(p)) {
		std::cout << "A" << std::endl;
	} else if (dynamic_cast<B*>(p)) {
		std::cout << "B" << std::endl;
	} else if (dynamic_cast<C*>(p)) {
		std::cout << "C" << std::endl;
	} else {
		std::cout << "Unknown type" << std::endl;
	}
}

void identify(Base& p){
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
	}
	catch (std::exception & e){
		try
		{
			(void)dynamic_cast<B&>(p);
			std::cout << "B" << std::endl;
		}
		catch (std::exception & e) {
			try
			{
				(void)dynamic_cast<C&>(p);
				std::cout << "C" << std::endl;
			}
			catch (std::exception & e) {
				std::cout << "Unknown type" << std::endl;
			}
		}
	}
}
