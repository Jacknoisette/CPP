/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 11:48:22 by jdhallen          #+#    #+#             */
/*   Updated: 2025/04/14 17:09:01 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>
#include <exception>

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
class Array {
	private :
		unsigned int	array_size;
	public :
		T	*array;
		Array(void);
		Array(unsigned int	i);
		~Array(void);
		Array(const Array &cpy);
		T				&operator[](unsigned int index);
		Array			&operator=(const Array &src);
		unsigned int	size(void);
};

#endif