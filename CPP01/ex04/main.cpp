/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:21:50 by codespace         #+#    #+#             */
/*   Updated: 2025/03/04 10:12:32 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	if (argc != 4){
		std::cout << "Error wrong arg" << std::endl;
		return -1;
	}
	std::string	filename = argv[1];
	std::string	s1 = argv[2];
	std::string	s2 = argv[3];
	std::ifstream fd1(filename.c_str());
	if (!fd1){
		std::cout << "Error with input file" << std::endl;
		return -1;
	}
	std::ofstream fd2((filename + ".replace").c_str(), std::ios::trunc);
	if (!fd2){
		std::cout << "Error with output file" << std::endl;
		return -1;
	}
	std::string line;
	while (std::getline(fd1, line)){
		if (line == s1)
			line = s2;
		fd2 << line << std::endl;
	}
	return 0;
}
