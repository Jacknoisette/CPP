/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 13:25:44 by codespace         #+#    #+#             */
/*   Updated: 2025/03/21 11:44:31 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::fractionalBits = 8;

Fixed::Fixed(void): rawBits(0){
	std::cout << "Default constructor called" << std::endl;
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