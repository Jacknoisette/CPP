/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 09:44:30 by codespace         #+#    #+#             */
/*   Updated: 2025/06/02 15:04:42 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int	test1(void)
{
	Span sp = Span(5);
	try{
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
	} catch (std::runtime_error & e) {
		return (std::cout << "Error : " << e.what() << std::endl, -1);
	}
	std::cout << "Span : ";
	for (unsigned int i = 0; i < sp.getSpan().size(); i++)
		std::cout << sp.getSpan()[i] << " ";
	std::cout << std::endl;
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	return (0);
}

void custom_seed() {
	static unsigned int counter = 8;
	srand((counter - 1) * counter * time(0));
	counter++;
}

int	test2(void)
{
	int test = 0;
	
	Span sp1(100);
	try{
		for (int i = 0; i < 101; i++){
			custom_seed();
			int	rand_nbr = rand() % 10000;
			sp1.addNumber(rand_nbr);
		}
		std::cout << WHITE << BIG << "Shortest Span" << RESET << std::endl;
		std::cout << sp1.shortestSpan() << std::endl;
		std::cout << WHITE << BIG << "Longest Span" << RESET << std::endl;
		std::cout << sp1.longestSpan() << std::endl;
	} catch (std::runtime_error & e) {
		std::cout << "Error : " << e.what() << std::endl;
		test++;
	}
	Span sp2 = Span();
	try{
		std::cout << WHITE << BIG << "Shortest Span" << RESET << std::endl;
		std::cout << sp2.shortestSpan() << std::endl;
	} catch (std::runtime_error & e) {
		std::cout << "Error : " << e.what() << std::endl;
		test++;
	}
	Span sp3 = Span();
	try{
		std::cout << WHITE << BIG << "Longest Span" << RESET << std::endl;
		std::cout << sp3.longestSpan() << std::endl;
	} catch (std::runtime_error & e) {
		std::cout << "Error : " << e.what() << std::endl;
		test++;
	}
	Span sp4 = Span(sp1);
	try{
		std::cout << WHITE << BIG << "Shortest Span" << RESET << std::endl;
		std::cout << sp1.shortestSpan() << std::endl;
		std::cout << WHITE << BIG << "Longest Span" << RESET << std::endl;
		std::cout << sp1.longestSpan() << std::endl;
	} catch (std::runtime_error & e) {
		std::cout << "Error : " << e.what() << std::endl;
		test++;
	}
	return (test);
}

int	test3(void)
{
	Span sp = Span(10000);
	std::vector<int> test;
	for (int i = 0; i < 9999; i++){
		custom_seed();
		int	rand_nbr = rand() % std::numeric_limits<int>::max();
		test.push_back(rand_nbr);
	}
	// std::cout << WHITE << BIG << "Span : " << RESET << ORANGE;
	// for (unsigned int i = 0; i < test.size(); i++)
	// 	std::cout << test[i] << " ";
	// std::cout << std::endl;
	try{
		custom_seed();
		int	rand_nbr = rand() % std::numeric_limits<int>::max();
		sp.addNumber(rand_nbr);
		sp.addRange(test.begin(), test.end());
	} catch (std::runtime_error & e) {
		return (std::cout << "Error : " << e.what() << std::endl, -1);
	}
	// std::cout << WHITE << BIG << "Span : " << RESET << YELLOW;
	// for (unsigned int i = 0; i < sp.getSpan().size(); i++)
	// 	std::cout << sp.getSpan()[i] << " ";
	// std::cout << std::endl;
	std::cout << WHITE << BIG << "Shortest Span" << RESET << std::endl;
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << WHITE << BIG << "Longest Span" << RESET << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	return (0);
}

int main(void)
{
	int	test;
	
	if (test1() == -1)
		std::cout << RED << "test1 failed" << RESET << std::endl;
	else
		std::cout << LIGHT_GREEN << "test1 OK" << RESET << std::endl;
	test = test2();
	if (test > 0)
		std::cout << RED << "test2 failed with " << test << " errors" << RESET << std::endl;
	else
		std::cout << LIGHT_GREEN << "test2 OK" << RESET << std::endl;
	if (test3() == -1)
		std::cout << RED << "test3 failed" << RESET << std::endl;
	else
		std::cout << LIGHT_GREEN << "test3 OK" << RESET << std::endl;
}
