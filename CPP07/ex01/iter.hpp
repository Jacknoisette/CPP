/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 11:48:22 by jdhallen          #+#    #+#             */
/*   Updated: 2025/05/05 16:44:34 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

# define RED "\033[1;30m"
# define PURPLE "\033[1;31m"
# define WHITE "\033[1;32m"
# define YELLOW "\033[1;33m"
# define ORANGE "\033[1;34m"
# define LIGHT_YELLOW "\033[1;35m"
# define LIGHT_GREEN "\033[1;36m"
# define GREY "\033[1;37m"
# define RESET "\033[0m"
# define BIG "\033[1m"

template <typename T>
void	iter(T *array_adr, int length, void (*function)(T &arg)){
	for (int i = 0; i < length; i++)
		function(array_adr[i]);
}

template <typename T>
void	iter(const T *array_adr, int length, void (*function)(const T &arg)){
	for (int i = 0; i < length; i++)
		function(array_adr[i]);
}

template <typename T>
void	printTemplate(T &arg){
	std::cout << WHITE << "Template value is : " << ORANGE << BIG << arg << RESET << std::endl;
}

template <typename T>
void	printTemplate(const T &arg){
	std::cout << WHITE << "Template value is : " << ORANGE << BIG << arg << RESET << std::endl;
}

#endif