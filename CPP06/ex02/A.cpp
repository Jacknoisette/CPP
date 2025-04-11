/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 09:14:44 by codespace         #+#    #+#             */
/*   Updated: 2025/04/11 10:17:28 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"

A::A(void){
}

A::~A(void){
}

std::ostream& operator<<(std::ostream& os, const A obj){
    (void)obj;
	os << "A";
	return (os);
}