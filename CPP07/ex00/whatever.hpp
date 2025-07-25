/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 11:48:22 by jdhallen          #+#    #+#             */
/*   Updated: 2025/06/02 14:21:56 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

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

template <typename T>
void	swap(T &arg1, T &arg2){
	T	temp;
	temp = arg1;
	arg1 = arg2;
	arg2 = temp;
}

template <typename T>
const T	min(const T &arg1, const T &arg2){
	if (arg1 < arg2)
		return (arg1);
	return (arg2);
}

template <typename T>
const T	max(const T &arg1, const T &arg2){
	if (arg1 > arg2)
		return (arg1);
	return (arg2);
}

#endif