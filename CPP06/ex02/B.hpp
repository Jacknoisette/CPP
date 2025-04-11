/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 09:15:00 by codespace         #+#    #+#             */
/*   Updated: 2025/04/11 10:16:30 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef B_HPP
# define B_HPP

#include <iostream>
#include "Base.hpp"

class B : public Base{
	public :
		B(void);
		virtual ~B(void);
};

std::ostream& operator<<(std::ostream& os, const B obj);

#endif