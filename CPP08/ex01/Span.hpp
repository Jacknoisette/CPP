/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 13:03:27 by jdhallen          #+#    #+#             */
/*   Updated: 2025/05/15 15:44:06 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>
#include <exception>
#include <iostream>
#include <iterator>
#include <vector>
# include <limits>

# define RED "\033[1;30m"
# define PURPLE "\033[1;31m"
# define WHITE "\033[1;32m"
# define YELLOW "\033[1;33m"
# define ORANGE "\033[1;34m"
# define PINK "\033[1;35m"
# define LIGHT_GREEN "\033[1;36m"
# define GREY "\033[1;37m"
# define RESET "\033[0m"
# define BIG "\033[1m"

class Span{
	private :
		unsigned int max_size;
	public :
		std::vector<int> span;
		Span(void);
		Span(unsigned int N);
		~Span(void);
		Span(const Span &cpy);
		Span &operator=(const Span &src);
		void	addNumber(int nbr);
		void	addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		int		shortestSpan(void);
		int		longestSpan(void);
};

#endif