/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:08:21 by jdhallen          #+#    #+#             */
/*   Updated: 2025/06/02 15:05:45 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <algorithm>
#include <exception>
#include <deque>
#include <iostream>
#include <iterator>
#include <list>
#include <vector>
#include <stack>

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

template <typename T>
class MutantStack : public std::stack<T>{
	public :
		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator begin();
		iterator end();
		MutantStack(void);
		~MutantStack(void);
		MutantStack(const MutantStack &cpy);
		MutantStack &operator=(const MutantStack &src);
};

#include "MutantStack.tpp"

#endif