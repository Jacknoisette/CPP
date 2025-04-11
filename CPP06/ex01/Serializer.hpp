/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 07:51:43 by codespace         #+#    #+#             */
/*   Updated: 2025/04/11 08:48:53 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include "Data.hpp"
# include <stdint.h>

# define RED "\033[1;30m"
# define PURPLE "\033[1;31m"
# define WHITE "\033[1;32m"
# define YELLOW "\033[1;33m"
# define ORANGE "\033[1;34m"
# define LIGHT_YELLOW "\033[1;35m"
# define LIGHT_GREEN "\033[1;36m"
# define GREY "\033[1;37m"
# define RESET "\033[0m"

class Serializer {
	private :
		Serializer(void);
		~Serializer(void);
	public :
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif