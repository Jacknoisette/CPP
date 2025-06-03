/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 09:44:30 by codespace         #+#    #+#             */
/*   Updated: 2025/06/03 10:12:10 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	test1(void)
{
	Data	dataOG("data", 1);
	uintptr_t	storage;

	std::cout << dataOG << std::endl;
	storage = Serializer::serialize(&dataOG);
	std::cout << "serialize ouput :   " << "0x" << std::hex << storage << std::endl;
	Data	*dataNew = Serializer::deserialize(storage);
	std::cout << "deserialize ouput : " << dataNew << std::endl;
	if (dataNew == &dataOG) {
		std::cout << "Success: dataNew points to the same object!" << std::endl;
	} else {
		std::cout << "Failure: dataNew doesn't point to the same object." << std::endl;
		return (-1);
	}
	std::cout << "OG " << dataOG << std::endl;
	std::cout << "New " << *dataNew << std::endl;
	return (0);
}

int	test2(void)
{
	Data	data1("data1", 1);
	Data	data2("data2", 2);
	Data	data3(data1);

	std::cout << data1 << std::endl;
	std::cout << data2 << std::endl;
	std::cout << data3 << std::endl;
	std::cout << "The number of data instance is " << Data::data_nbr << std::endl;
	data3 = data2;
	std::cout << data1 << std::endl;
	std::cout << data2 << std::endl;
	std::cout << data3 << std::endl;
	std::cout << "The number of data instance is " << Data::data_nbr << std::endl;
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
}
