/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 11:45:36 by jdhallen          #+#    #+#             */
/*   Updated: 2025/06/10 11:46:42 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <algorithm>
#include <exception>
#include <iostream>
#include <iterator>
#include <vector>
#include <deque>
#include <set>
#include <limits>
#include <sstream>
#include <sys/time.h>
#include <iostream>
#include <iomanip>

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
class PmergeMe{
	private :
		T	OGStack;
		T	*Package;
		T	MaxStack;
		T	MinStack;
	public :
		PmergeMe(void);
		PmergeMe(T _OGStack, T *_Package, T _MaxStack, T _MinStack);
		~PmergeMe(void);
		PmergeMe(const PmergeMe<T> &cpy);
		PmergeMe &operator=(const PmergeMe<T> &src);

		void	setOGStack(T _OGStack);
		void	setPackage(T *_Package);
		void	setMaxStack(T _MaxStack);
		void	setMinStack(T _MinStack);

		T	getOGStack(void);
		T	*getPackage(void);
		T	getMaxStack(void);
		T	getMinStack(void);

		void	Exec(void);
		int		Step1(void);
		int		Step2(const int Package_nbr);
		int		Step3(const int Package_nbr);
		int		Step4(void);
		int		Step5(void);
		int		Step6(void);

};

template <typename T>
bool	is_sort(T& stack){
	if (stack.size() < 2)
		return (true);
	for (unsigned int i = 1; i < stack.size(); i++)
		if (stack[i] < stack[i - 1])
			return (false);
	return (true);

}

template <typename T>
void	display_container(T* container){
	for (typename T::iterator i = container->begin(); i != container->end(); i++)
		std::cout << *i << " ";
	std::cout << std::endl;
}
long	getTimeMicro(void);

#endif