/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 09:15:00 by codespace         #+#    #+#             */
/*   Updated: 2025/04/11 10:16:33 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_HPP
# define A_HPP

#include <iostream>
#include "Base.hpp"

class A : public Base{
	public :
		A(void);
		virtual ~A(void);
};

std::ostream& operator<<(std::ostream& os, const A obj);

#endif