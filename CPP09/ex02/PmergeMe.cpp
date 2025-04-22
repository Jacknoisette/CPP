/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 11:45:45 by jdhallen          #+#    #+#             */
/*   Updated: 2025/04/22 15:45:20 by jdhallen         ###   ########.fr       */
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
	delete Package;
}

template <typename T>
PmergeMe<T>::PmergeMe(const PmergeMe<T> &cpy){
	Package = new T[0];
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
			setPackage(new T[src.getOGStack().size() / 2])
			for (int i = 0; i < src.getOGStack().size() / 2; i++)
				Package[i] = src.Package[i];
		}
		else{
			setPackage(new T[(src.getOGStack().size() / 2) + 1])
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
	int Package_nbr = Step1();
	Step2(Package_nbr);
	Step3();
	Step4();
	Step5();
	Step6();
}

template <typename T>
int		PmergeMe<T>::Step1(void){
	int size;
	bool odd = false;
	if (getOGStack() % 2 == 0)
		size = getOGStack().size() / 2
	else {
		setPackage(new T[(getOGStack().size() / 2) + 1])
		odd = true;
	}
	int Package_nbr = 0;
	for (int i = 0; i < size * 2; i++){
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
		if (Package[i].size() == 2)
			if (Package[i][0] > Package[i][1])
				int temp = Package[i][0];
				Package[i][0] = Package[i][1];
				Package[i][1] = temp;
	}
}

template <typename T>
int		PmergeMe<T>::Step3(void){

}

template <typename T>
int		PmergeMe<T>::Step4(void){

}

template <typename T>
int		PmergeMe<T>::Step5(void){

}

template <typename T>
int		PmergeMe<T>::Step6(void){

}


