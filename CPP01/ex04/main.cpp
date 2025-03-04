/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:21:50 by codespace         #+#    #+#             */
/*   Updated: 2025/03/03 15:50:17 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	if (argc != 4)
		return -1;
	std::string	filename = argv[1];
	std::string	s1 = argv[2];
	std::string	s2 = argv[3];
	
	std::ifstream fd1(filename.c_str());
	if (!fd1)
		return -1;
	std::ofstream fd2((filename + ".replace").c_str(), std::ios::trunc);
	if (!fd2)
		return -1;
	std::string line;
	while (std::getline(fd1, line))
	{
		if (line == s1)
			line = s2;
		fd2 << line << std::endl;
	}
	return 0;
}