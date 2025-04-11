/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 09:14:44 by codespace         #+#    #+#             */
/*   Updated: 2025/04/11 11:17:00 by codespace        ###   ########.fr       */
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

Base * Base::generate(int checker){
	(void)checker;
	custom_seed();
	int	rand_nbr = rand() % 3;
	switch (rand_nbr)
	{
		case 0 :
		{
			std::cout << "A : ";
			break ;
		}
;		case 1 :
		{
			std::cout << "B : ";
			break ;
		}
		case 2 :
		{
			std::cout << "C : ";
			break ;
		}
	}
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

Base * Base::generate(void){
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

void Base::identify(Base* p){
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

void Base::identify(Base& p){
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
