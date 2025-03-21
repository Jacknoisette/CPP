/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 13:26:21 by codespace         #+#    #+#             */
/*   Updated: 2025/03/21 11:44:38 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::fractionalBits = 8;

Fixed::Fixed(void): rawBits(0){
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int integer){
	std::cout << "Int constructor called" << std::endl;
	rawBits = integer << fractionalBits;
}

Fixed::Fixed(const float floating){
	std::cout << "Float constructor called" << std::endl;
	rawBits = static_cast<int>(floating * (1 << fractionalBits) + 0.5f);
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
	return rawBits;
}

void Fixed::setRawBits(int const raw){
	rawBits = raw;
}

float Fixed::toFloat(void) const{
	return static_cast<float>(getRawBits()) / (1 << fractionalBits);
}

int Fixed::toInt(void) const{
	return getRawBits() >> fractionalBits;
}

std::ostream& operator<<(std::ostream& os, const Fixed& obj) {
	os << obj.toFloat();
	return os;
}