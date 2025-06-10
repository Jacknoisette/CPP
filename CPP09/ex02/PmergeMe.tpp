/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 12:04:10 by jdhallen          #+#    #+#             */
/*   Updated: 2025/06/10 12:04:31 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

template <typename T>
PmergeMe<T>::PmergeMe(void)
	: OGStack(NULL), Package(NULL), MaxStack(NULL), MinStack(NULL){
}

template <typename T>
PmergeMe<T>::PmergeMe(T _OGStack, T *_Package, T _MaxStack, T _MinStack)
	: OGStack(_OGStack), Package(_Package), MaxStack(_MaxStack), MinStack(_MinStack){
}

template <typename T>
PmergeMe<T>::~PmergeMe(void){
	delete[] Package;
}

template <typename T>
PmergeMe<T>::PmergeMe(const PmergeMe<T> &cpy) : Package(NULL){
	*this = cpy;
}

template <typename T>
PmergeMe<T>	&PmergeMe<T>::operator=(const PmergeMe<T> &src){
	if (this != &src)
	{
		if (Package)
			delete[] Package;
		OGStack = src.OGStack;
		if (getOGStack() % 2 == 0){
			setPackage(new T[src.getOGStack().size() / 2]);
			for (int i = 0; i < src.getOGStack().size() / 2; i++)
				Package[i] = src.Package[i];
		}
		else{
			setPackage(new T[(src.getOGStack().size() / 2) + 1]);
			for (int i = 0; i < (src.getOGStack().size() / 2) + 1; i++)
				Package[i] = src.Package[i];
		}
		MaxStack = src.MaxStack;
		MinStack = src.MinStack;
	}
	return (*this);
}

template <typename T>
void	PmergeMe<T>::setOGStack(T _OGStack){
	OGStack = _OGStack;
}

template <typename T>
void	PmergeMe<T>::setPackage(T *_Package){
	Package = _Package;
}

template <typename T>
void	PmergeMe<T>::setMaxStack(T _MaxStack){
	MaxStack = _MaxStack;
}

template <typename T>
void	PmergeMe<T>::setMinStack(T _MinStack){
	MinStack = _MinStack;
}

template <typename T>
T	PmergeMe<T>::getOGStack(void){
	return (OGStack);
}

template <typename T>
T	*PmergeMe<T>::getPackage(void){
	return (Package);
}

template <typename T>
T	PmergeMe<T>::getMaxStack(void){
	return (MaxStack);
}

template <typename T>
T	PmergeMe<T>::getMinStack(void){
	return (MinStack);
}

template <typename T>
void	PmergeMe<T>::Exec(void){
	int Package_nbr = this->Step1();
	this->Step2(Package_nbr);
	this->Step3(Package_nbr);
	this->Step4();
	this->Step5();
	this->Step6();
}

template <typename T>
int		PmergeMe<T>::Step1(void){
	unsigned int size;
	bool odd = false;
	if (getOGStack().size() % 2 == 0)
		size = getOGStack().size() / 2;
	else {
		size = getOGStack().size() / 2 + 1;
		odd = true;
	}
	setPackage(new T[size]);
	unsigned int Package_nbr = 0;
	for (unsigned int i = 0; i < size * 2; i++){
		if (i < getOGStack().size())
			Package[Package_nbr].push_back(getOGStack()[i]);
		if (i % 2 == 1)
			Package_nbr++;
	}
	return (Package_nbr);
}

template <typename T>
int		PmergeMe<T>::Step2(const int Package_nbr){
	for (int i = 0; i < Package_nbr; i++){
		if (Package[i].size() == 2){
			if (Package[i][0] > Package[i][1]){
				int temp = Package[i][0];
				Package[i][0] = Package[i][1];
				Package[i][1] = temp;
			}
		}
	}
	return (0);
}

template <typename T>
int		PmergeMe<T>::Step3(const int Package_nbr){
	for (int i = 0; i < Package_nbr; i++)
	{
		if (Package[i].size() == 2)
		{
			MinStack.push_back(Package[i][0]);
			MaxStack.push_back(Package[i][1]);
		}
		else
		{
			MaxStack.push_back(Package[i][0]);
		}
	}
	return (0);
}

template <typename T>
int		PmergeMe<T>::Step4(void){
	if (is_sort(MaxStack)){
		return (0);
	}
	T NewMaxStack;
	T NewMinStack;
	PmergeMe<T>	MaxRecursion(MaxStack, NULL, NewMaxStack, NewMinStack);
	MaxRecursion.Exec();
	MaxStack = MaxRecursion.getOGStack();
	return (0);
}

template <typename T>
int		PmergeMe<T>::Step5(void){
	while (!MinStack.empty())
	{
		int				nbr = MinStack[0];
		unsigned int	min = 0;
		unsigned int	max = MaxStack.size();
		
		while (min < max)
		{
			unsigned int	median = (max + min) / 2;
			if (MaxStack[median] < nbr)
				min = median + 1;
			else
				max = median;
		}
		MaxStack.insert(MaxStack.begin() + min, nbr);
		MinStack.erase(MinStack.begin());
	}
	return (0);
}

template <typename T>
int		PmergeMe<T>::Step6(void){
	setOGStack(getMaxStack());
	return (1);
}

// template <typename T>
// bool	is_sort(T stack)

// template <typename T>
// void	display_container(T container)
