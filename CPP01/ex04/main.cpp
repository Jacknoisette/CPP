/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 11:14:57 by jdhallen          #+#    #+#             */
/*   Updated: 2025/04/03 11:16:22 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	if (argc != 4){
		std::cout << "Error: wrong arg" << std::endl;
		return -1;
	}
	std::string	filename = argv[1];
	std::string	s1 = argv[2];
	std::string	s2 = argv[3];
	std::ifstream fd1(filename.c_str());
	if (s1.empty()){
		std::cout << "Error: try to replace with empty string" << std::endl;
		return -1;
	}
	if (!fd1){
		std::cout << "Error: with input file" << std::endl;
		return -1;
	}
	std::ofstream fd2((filename + ".replace").c_str(), std::ios::trunc);
	if (!fd2){
		std::cout << "Error: with output file" << std::endl;
		return -1;
	}
	std::string line;
	while (std::getline(fd1, line)){
		size_t pos = 0;
		while ((pos = line.find(s1, pos)) != std::string::npos){
			line = line.substr(0, pos) + s2 + line.substr(pos + s1.length());
			pos += s2.length();
		}
		fd2 << line << std::endl;
	}
	return 0;
}
