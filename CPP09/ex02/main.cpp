/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 09:44:30 by codespace         #+#    #+#             */
/*   Updated: 2025/04/22 14:33:49 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

template <typename T>
bool	check_double_occurence(T *container)
{
	for (unsigned int i = 0; i < container->size(); i++)
		for (unsigned int j = 0; j < container->size(); j++)
			if (i != j && (*container)[i] == (*container)[j])
				return (std::cout << "Error: Multiple occurence of: " << (*container)[i] << std::endl, false);
	return (true);
}

bool	parsing(std::vector<int> *Vstack, std::deque<int> *Dstack, int argc, char **argv)
{
	int i = 1;
	while (i < argc)
	{
		int j = 0;
		while (argv[i][j] != '\0')
		{
			if (std::isspace(argv[i][j]))
				break ;
			if (!std::isdigit(argv[i][j]))
				return (std::cout << "Error: Char is not a digit" << std::endl, false);
			j++;
		}
		long	tester = std::atol(argv[i]);
		if (tester < 0 || tester > std::numeric_limits<int>::max())
			return (std::cout << "Error: Number does not fit requirement" << std::endl, false);
		Vstack->push_back(static_cast<int>(tester));
		Dstack->push_back(static_cast<int>(tester));
		i++;
	}
	if (!check_double_occurence(Vstack) || !check_double_occurence(Dstack))
		return (false);
	return (true);
}

template <typename T>
void	display_container(T container)
{
	for (typename T::iterator i = container.begin(); i != container.end(); i++)
		std::cout << *i << " ";
	std::cout << std::endl;
}

int main(int argc, char **argv)
{
	if (argc == 1)
		return (std::cout << "Error: No Arg is provided" << std::endl, -1);
	std::vector<int> Vstack;
	std::deque<int> Dstack; 
	if (!parsing(&Vstack, &Dstack, argc, argv))
		return (-1);
	std::cout << "Before Vstack: ";
	display_container(Vstack);
	std::cout << "Before Dstack: ";
	display_container(Dstack);
}
