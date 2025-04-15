/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 13:26:21 by codespace         #+#    #+#             */
/*   Updated: 2025/04/15 10:35:36 by jdhallen         ###   ########.fr       */
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
	*this = ref;
}

Fixed& Fixed::operator=(const Fixed& ref){
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &ref){
		rawBits = ref.getRawBits();
    }
    return *this;
}

int Fixed::getRawBits(void) const{
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

int Fixed::operator>(const Fixed& other) const{
	return rawBits > other.rawBits;
}

int Fixed::operator<(const Fixed& other) const{
	return rawBits < other.rawBits;
}

int Fixed::operator>=(const Fixed& other) const{
	return rawBits >= other.rawBits;
}

int Fixed::operator<=(const Fixed& other) const{
	return rawBits <= other.rawBits;
}

int Fixed::operator==(const Fixed& other) const{
	return rawBits == other.rawBits;
}

int Fixed::operator!=(const Fixed& other) const{
	return rawBits != other.rawBits;
}

Fixed Fixed::operator+(const Fixed& other) const{
	return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other) const{
	return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other) const{
	return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) const{
	if (this->rawBits == 0 || other.rawBits == 0)
	{
		std::cout << "Division by 0 is forbidden" << std::endl;
		return Fixed();
	}
	return Fixed(this->toFloat() / other.toFloat());
}

Fixed& Fixed::operator++(){
	rawBits += 1;
	return *this;
}  // ++x

Fixed Fixed::operator++(int){
	Fixed temp = *this;
	rawBits += 1;
	return temp;
}  // x++

Fixed& Fixed::operator--(){
	rawBits -= 1;
	return *this;
}  // --x

Fixed Fixed::operator--(int){
	Fixed temp = *this;
	rawBits -= 1;
	return temp;
}  // x--

Fixed& min(Fixed& a, Fixed& b){
	return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b){
	return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b){
	return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b){
	return (a > b) ? a : b;
}