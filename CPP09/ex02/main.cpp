/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 09:44:30 by codespace         #+#    #+#             */
/*   Updated: 2025/06/10 11:58:16 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include "PmergeMe.tpp"

template <typename T>
bool	check_double_occurence(T *container)
{
	std::set<typename T::value_type> seen;
	for (typename T::iterator it = container->begin(); it != container->end(); ++it) {
		if (!seen.insert(*it).second) {
			std::cout << "Error: Multiple occurence of: " << *it << std::endl;
			return false;
		}
	}
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

bool	execStack(std::vector<int> *Vstack, std::deque<int> *Dstack, long *Vtime, long *Dtime)
{
	std::vector<int> VMaxStack;
	std::vector<int> VMinStack;
	PmergeMe<std::vector<int> >	Vsort(*Vstack, NULL, VMaxStack, VMinStack);
	long	Vstart = getTimeMicro();
	Vsort.Exec();
	*Vstack = Vsort.getOGStack();
	if (!Vstack)
		return (false);
	long	Vend = getTimeMicro();

	std::deque<int> DMaxStack;
	std::deque<int> DMinStack;
	PmergeMe<std::deque<int> >	Dsort(*Dstack, NULL, DMaxStack, DMinStack);
	long	Dstart = getTimeMicro();
	Dsort.Exec();
	*Dstack = Dsort.getOGStack();
	if (!Dstack)
		return (false);
	long	Dend = getTimeMicro();

	*Vtime = Vend - Vstart;
	*Dtime = Dend - Dstart;
	return (true);
}

void display_time(long time_us) {
	if (time_us >= 1000000)
		std::cout << std::fixed << std::setprecision(3) << (double)time_us / 1000000 << " s" << std::endl;
	else if (time_us >= 1000)
		std::cout << std::fixed << std::setprecision(3) << (double)time_us / 1000 << " ms" << std::endl;
	else
		std::cout << time_us << " us" << std::endl;
}

int main(int argc, char **argv)
{
	if (argc == 1)
		return (std::cout << "Error: No Arg is provided" << std::endl, -1);
	std::vector<int> Vstack;
	std::deque<int> Dstack; 
	long parsingtimestart = getTimeMicro(); 
	if (!parsing(&Vstack, &Dstack, argc, argv))
		return (0);
	long parsingtimeend = getTimeMicro(); 
	std::cout << "Before : ";
	display_container(&Vstack);

	long Vtime = 0;
	long Dtime = 0;
	execStack(&Vstack, &Dstack, &Vtime, &Dtime);
	if (!is_sort(Vstack))
		std::cout << "Error, Vector is not sort !" << std::endl;
	if (!is_sort(Dstack))
		std::cout << "Error, Deque is not sort !" << std::endl;
	
	std::cout << "After :  ";
	display_container(&Vstack);
	std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector : " ; //<< Vtime << " us" << std::endl; 
	display_time(Vtime);
	std::cout << "Time to process a range of " << argc - 1 << " elements with std::deque  : "; // << Dtime << " us" << std::endl; 
	display_time(Dtime);
	std::cout << "Time for parsing" << std::endl;
	display_time(parsingtimeend - parsingtimestart);
	return (0);
}
