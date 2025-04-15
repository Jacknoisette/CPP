/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 09:44:30 by codespace         #+#    #+#             */
/*   Updated: 2025/04/15 11:42:10 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include "easyfind.tpp"

int	test1(void)
{
	std::cout << WHITE << BIG << "Container Vector :" << RESET << std::endl;
	int data[] = {1, 390, 234, 56, -30, 39};
	std::vector<int> container1;
	for (int i = 0; i < 6; i++)
		container1.push_back(data[i]);
	try{
		::easyfind(container1, 56);
	} catch (std::runtime_error &e){
		return (std::cout << "ERROR : " << e.what() << std::endl, -1);
	}
	try{
		::easyfind(container1, 39);
	} catch (std::runtime_error &e){
		return (std::cout << "ERROR : " << e.what() << std::endl, -1);
	}
	try{
		::easyfind(container1, 4);
	} catch (std::runtime_error &e){
		return (std::cout << "ERROR : " << e.what() << std::endl, -1);
	}
	return (0);
}

int	test2(void)
{
	std::cout << WHITE << BIG << "Container Deque :" << RESET << std::endl;
	int data[] = {8, 30, 103, 5567, 2, -30};
	std::deque<int> container1;
	for (int i = 0; i < 6; i++)
		container1.push_back(data[i]);
	try{
		::easyfind(container1, -30);
	} catch (std::runtime_error &e){
		return (std::cout << "ERROR : " << e.what() << std::endl, -1);
	}
	try{
		::easyfind(container1, 8);
	} catch (std::runtime_error &e){
		return (std::cout << "ERROR : " << e.what() << std::endl, -1);
	}
	try{
		::easyfind(container1, 44);
	} catch (std::runtime_error &e){
		return (std::cout << "ERROR : " << e.what() << std::endl, -1);
	}
	return (0);
}

int	test3(void)
{
	std::cout << WHITE << BIG << "Container List :" << RESET << std::endl;
	int data[] = {-40, 90, 783, 3679, 45, 901};
	std::list<int> container1;
	for (int i = 0; i < 6; i++)
		container1.push_back(data[i]);
	try{
		::easyfind(container1, 901);
	} catch (std::runtime_error &e){
		return (std::cout << "ERROR : " << e.what() << std::endl, -1);
	}
	try{
		::easyfind(container1, 3679);
	} catch (std::runtime_error &e){
		return (std::cout << "ERROR : " << e.what() << std::endl, -1);
	}
	try{
		::easyfind(container1, 83);
	} catch (std::runtime_error &e){
		return (std::cout << "ERROR : " << e.what() << std::endl, -1);
	}
	return (0);
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
		std::cout << LIGHT_GREEN << "test1 OK" << RESET << std::endl;
	if (test3() == -1)
		std::cout << RED << "test3 failed" << RESET << std::endl;
	else
		std::cout << LIGHT_GREEN << "test3 OK" << RESET << std::endl;
}
