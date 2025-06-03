/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 09:44:30 by codespace         #+#    #+#             */
/*   Updated: 2025/06/02 15:05:51 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int	test1(void)
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "Top of the mstack : " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "Size of the mstack : " << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	std::cout << "Content of the mstack : ";
	while (it != ite)
	{
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;
	std::stack<int> s(mstack);
	return (0);
}

void custom_seed() {
	static unsigned int counter = 8;
	srand((counter - 1) * counter * time(0));
    counter++;
}

int	test2(void)
{
	MutantStack<int> mstack;
	for (int i = 0; i < 100; i++){
		custom_seed();
		int	rand_nbr = rand() % 10000;
		mstack.push(rand_nbr);
	}
	custom_seed();
	int max = rand() % 90;
	for (int i = 0; i < max; i++){
		mstack.pop();
	}
	MutantStack<int>::iterator b1 = mstack.begin();
	MutantStack<int>::iterator e1 = mstack.end();
	std::cout << "Content of the mstack :" << std::endl;
	while (b1 != e1)
	{
		std::cout << *b1 << std::endl;
		++b1;
	}
	MutantStack<int> mstacksort(mstack);
	std::cout << "Content of the mstacksort" << std::endl;
	MutantStack<int>::iterator b2 = mstacksort.begin();
	MutantStack<int>::iterator e2 = mstacksort.end();
	std::sort(b2, e2);
	while (b2 != e2)
	{
		std::cout << *b2 << std::endl;
		++b2;
	}
	mstacksort = mstack;
	std::cout << "Operator test on mstacksort -> mstack" << std::endl;
	MutantStack<int>::iterator b3 = mstacksort.begin();
	MutantStack<int>::iterator e3 = mstacksort.end();
	while (b3 != e3)
	{
		std::cout << *b3 << std::endl;
		++b3;
	}
	return (0);
}

int	test3(void)
{
	int nbr ;
	
	MutantStack<int> mstack;
	std::list<int>	lstack;
	std::vector<int>	vstack;
	nbr = 5; mstack.push(nbr); lstack.push_back(nbr); vstack.push_back(nbr);
	nbr = 17; mstack.push(nbr); lstack.push_back(nbr); vstack.push_back(nbr);
	std::cout << "Top of the mstack : " << mstack.top() << " Top of the lstack : " << lstack.back() << " Top of the vstack : " << vstack.back() << std::endl;
	mstack.pop(); lstack.pop_back(); vstack.pop_back();
	std::cout << "Size of the mstack : " << mstack.size() << " Size of the lstack : " << lstack.size() << " Size of the vstack : " << vstack.size() << std::endl;
	nbr = 3; mstack.push(nbr); lstack.push_back(nbr); vstack.push_back(nbr);
	nbr = 5; mstack.push(nbr); lstack.push_back(nbr); vstack.push_back(nbr);
	nbr = 737; mstack.push(nbr); lstack.push_back(nbr); vstack.push_back(nbr);
	nbr = 0; mstack.push(nbr); lstack.push_back(nbr); vstack.push_back(nbr);
	MutantStack<int>::iterator mit = mstack.begin(); std::list<int>::iterator lit = lstack.begin(); std::vector<int>::iterator vit = vstack.begin();
	MutantStack<int>::iterator mite = mstack.end(); std::list<int>::iterator lite = lstack.end(); std::vector<int>::iterator vite = vstack.end();
	++mit; ++lit; ++vit;
	--mit; --lit; --vit;
	std::cout << "m  l  v content of stacks ";
	while (mit != mite && lit != lite && vit != vite)
	{
		std::cout << *mit << " "  << *lit << " " << *vit << " " << std::endl;
		if (*mit != *lit || *lit != *vit || *mit != *vit)
			return (-1);
		++mit; ++lit; ++vit;
	}
	std::cout << std::endl;
	std::stack<int> m(mstack); std::list<int> l(lstack); std::vector<int> v(vstack);
	return (0);
}

int main(void)
{
	if (test1() == -1)
		std::cout << RED << "test1 failed" << RESET << std::endl;
	else
		std::cout << LIGHT_GREEN << "test1 OK" << RESET << std::endl;
	if (test2() == -1)
		std::cout << RED << "test2 failed" << RESET << std::endl;
	else
		std::cout << LIGHT_GREEN << "test2 OK" << RESET << std::endl;
	if (test3() == -1)
		std::cout << RED << "test3 failed" << RESET << std::endl;
	else
		std::cout << LIGHT_GREEN << "test3 OK" << RESET << std::endl;
}
