/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 13:25:44 by codespace         #+#    #+#             */
/*   Updated: 2025/03/05 13:26:41 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void){
	std::cout << "Default constructor called" << std::endl;
	rawBits = 0;
}

Fixed::~Fixed(void){
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& ref){
	std::cout << "Copy constructor called" << std::endl;
	rawBits = ref.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& ref) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &ref) {
		rawBits = ref.getRawBits();
    }
    return *this;
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return rawBits;
}

void Fixed::setRawBits(int const raw){
	std::cout << "setRawBits member function called" << std::endl;
	rawBits = raw << fractionalBits;
}