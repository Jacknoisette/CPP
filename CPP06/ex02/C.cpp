/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 09:14:44 by codespace         #+#    #+#             */
/*   Updated: 2025/04/11 10:16:36 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "C.hpp"

C::C(void){
}

C::~C(void){
}

std::ostream& operator<<(std::ostream& os, const C obj){
    (void)obj;
	os << "C";
	return (os);
}