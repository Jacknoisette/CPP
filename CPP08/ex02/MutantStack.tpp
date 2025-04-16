/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:10:08 by jdhallen          #+#    #+#             */
/*   Updated: 2025/04/16 11:04:22 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack(void){
}

template <typename T>
MutantStack<T>::~MutantStack(void){
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T> &cpy) : std::stack<T>(cpy){
}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack<T> &src){
	if (this != &src) {
		std::stack<T>::operator=(src);
	}
	return (*this);
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() { 
	return this->c.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() {
	return this->c.end();
}