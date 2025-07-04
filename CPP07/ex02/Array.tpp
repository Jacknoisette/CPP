/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 15:06:17 by jdhallen          #+#    #+#             */
/*   Updated: 2025/06/02 14:40:54 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array(void) : array_size(0){
	array = new T[0];
}

template <typename T>
Array<T>::Array(unsigned int i) : array_size(i){
	array = new T[i];
}

template <typename T>
Array<T>::~Array(void){
	delete[] array;
}

template <typename T>
Array<T>::Array(const Array<T> &cpy) : array_size(cpy.array_size){
	array = new T[cpy.array_size];
	for (unsigned int i = 0; i < array_size; i++)
		array[i] = cpy.array[i];
}

template <typename T>
Array<T>	&Array<T>::operator=(const Array<T> &src){
	if (this != &src)
	{
		if (array)
			delete[] array;
		array = NULL;
		array_size = src.array_size;
		array = new T[array_size];
		for (unsigned int i = 0; i < array_size; i++)
			array[i] = src.array[i];
	}
	return (*this);
}

template <typename T>
unsigned int	Array<T>::size(void) const{
	return (array_size);
}

template <typename T>
T		&Array<T>::operator[](const unsigned int &index){
	if (index >= array_size)
		throw std::exception();
	return (array[index]);
}
