/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 12:16:14 by jdhallen          #+#    #+#             */
/*   Updated: 2025/04/16 14:41:49 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <algorithm>
#include <exception>
#include <iostream>
#include <iterator>
#include <map>
#include <fstream>
#include <fcntl.h>
#include <limits>

# define RED "\033[1;30m"
# define PURPLE "\033[1;31m"
# define WHITE "\033[1;32m"
# define YELLOW "\033[1;33m"
# define ORANGE "\033[1;34m"
# define PINK "\033[1;35m"
# define LIGHT_GREEN "\033[1;36m"
# define GREY "\033[1;37m"
# define RESET "\033[0m"
# define BIG "\033[1m"

class  Date {
	private :
		int year;
		int month;
		int day;
	public :
		Date(void);
		Date(int _year, int _month, int _day);
		~Date(void);
		Date(const Date &cpy);
		Date &operator=(const Date &src);
		bool operator<(const Date& other) const;
		bool operator==(const Date& other) const;
		void	findNearestValueInMap(const std::map<Date, float> &btcDataBase, float bitcoinNbr);
		void	setYear(int _new_year);
		void	setMonth(int _new_month);
		void	setDay(int _new_day);
		int		getYear(void) const;
		int		getMonth(void) const;
		int		getDay(void) const;
};

std::ostream& operator<<(std::ostream& os, const Date& obj);

#endif