/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 09:15:00 by codespace         #+#    #+#             */
/*   Updated: 2025/04/11 10:16:39 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C_HPP
# define C_HPP

#include <iostream>
#include "Base.hpp"

class C : public Base{
	public :
		C(void);
		virtual ~C(void);
};

std::ostream& operator<<(std::ostream& os, const C obj);

#endif