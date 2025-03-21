/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 13:26:16 by codespace         #+#    #+#             */
/*   Updated: 2025/03/21 11:45:03 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class	Fixed
{
	private :
		static const int	fractionalBits;
		int					rawBits;
	public :
		Fixed(void);
		Fixed(const int integer);
		Fixed(const float floating);
		Fixed(const Fixed& ref);
		~Fixed(void);
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;

		Fixed& operator=(const Fixed& ref);
		
		int operator>(const Fixed& other) const;
		int operator<(const Fixed& other) const;
		int operator>=(const Fixed& other) const;
		int operator<=(const Fixed& other) const;
		int operator==(const Fixed& other) const;
		int operator!=(const Fixed& other) const;
		
		Fixed operator+(const Fixed& other) const;
		Fixed operator-(const Fixed& other) const;
		Fixed operator*(const Fixed& other) const;
		Fixed operator/(const Fixed& other) const;

		Fixed& operator++();    // ++x
		Fixed operator++(int);  // x++
		Fixed& operator--();    // --x
		Fixed operator--(int);  // x--
		
		static Fixed& min(Fixed& a, Fixed& b);
		static const Fixed& min(const Fixed& a, const Fixed& b);
		static Fixed& max(Fixed& a, Fixed& b);
		static const Fixed& max(const Fixed& a, const Fixed& b);

};

std::ostream& operator<<(std::ostream& os, const Fixed& obj);

#endif