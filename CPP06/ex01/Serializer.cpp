/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 08:07:42 by codespace         #+#    #+#             */
/*   Updated: 2025/04/11 08:36:41 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(void){
}

Serializer::~Serializer(void){
}

uintptr_t Serializer::serialize(Data* ptr){
	uintptr_t raw = reinterpret_cast<uintptr_t>(ptr);
	return (raw);
}

Data* Serializer::deserialize(uintptr_t raw){
	Data *ptr = reinterpret_cast<Data*>(raw);
	return (ptr);
}