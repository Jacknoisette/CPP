/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 13:26:16 by codespace         #+#    #+#             */
/*   Updated: 2025/03/21 11:44:48 by jdhallen         ###   ########.fr       */
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
		Fixed& operator=(const Fixed& ref);
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;

};

std::ostream& operator<<(std::ostream& os, const Fixed& obj);

#endif