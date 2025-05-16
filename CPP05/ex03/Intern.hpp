/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 12:12:36 by jdhallen          #+#    #+#             */
/*   Updated: 2025/04/09 13:43:48 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Intern_HPP
# define Intern_HPP

# include <iostream> 
# include <exception>
# include <string.h>

#define RED "\033[1;30m"
#define PURPLE "\033[1;31m"
#define WHITE "\033[1;32m"
#define YELLOW "\033[1;33m"
#define ORANGE "\033[1;34m"
#define LIGHT_YELLOW "\033[1;35m"
#define LIGHT_GREEN "\033[1;36m"
#define GREY "\033[1;37m"
#define RESET "\033[0m"

class AForm;

class Intern {
	public :
		Intern(void);
		~Intern(void);
		Intern(const Intern &copy);
		Intern	&operator=(const Intern &src);
		AForm	*makeForm(std::string name, std::string target);
};

std::ostream& operator<<(std::ostream& os, const Intern& obj);

#endif