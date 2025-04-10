/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 10:27:42 by jdhallen          #+#    #+#             */
/*   Updated: 2025/04/10 15:32:10 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <cstdlib>
# include <cctype>
# include <exception>
# include <limits>
# include <cerrno>
# include <string>
# include <sstream>
# include <iomanip>
# include <cmath>

#define RED "\033[1;30m"
#define PURPLE "\033[1;31m"
#define WHITE "\033[1;32m"
#define YELLOW "\033[1;33m"
#define ORANGE "\033[1;34m"
#define LIGHT_YELLOW "\033[1;35m"
#define LIGHT_GREEN "\033[1;36m"
#define GREY "\033[1;37m"
#define RESET "\033[0m"

#ifndef	DEFAULT
# define DEFAULT -1
#endif
#ifndef	CHAR
# define CHAR 0
#endif
#ifndef	INT
# define INT 1
#endif
#ifndef	FLOAT
# define FLOAT 2
#endif
#ifndef	DOUBLE
# define DOUBLE 3
#endif

class ScalarConverter {
	private :
		ScalarConverter(void);
		virtual ~ScalarConverter(void);
	public :
		static void	convert(const std::string &input);
};

void		convertToAllType(std::string &input, void *ptr, int type);
std::string	removeWhitespace(const std::string &input);
int			checkOGType(const std::string &input);
void		*checkLimitType(const std::string &input, int type);
void		*checkLimitTypeSpe(const std::string &input, int type);
void		display_type(int type);
void		delete_type(void *ptr, int type);

#endif