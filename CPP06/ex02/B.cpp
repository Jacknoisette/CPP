/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 09:14:44 by codespace         #+#    #+#             */
/*   Updated: 2025/04/11 10:16:26 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "B.hpp"

B::B(void){
}

B::~B(void){
}

std::ostream& operator<<(std::ostream& os, const B obj){
    (void)obj;
	os << "B";
	return (os);
}