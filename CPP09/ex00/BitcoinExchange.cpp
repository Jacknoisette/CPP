/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 10:41:45 by jdhallen          #+#    #+#             */
/*   Updated: 2025/06/10 11:10:39 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void) : year(0), month(0), day(0){

}

BitcoinExchange::BitcoinExchange(int _year, int _month, int _day) : year(_year), month(_month), day(_day){
}

BitcoinExchange::~BitcoinExchange(void){
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &cpy){
	*this = cpy;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &src){
	if (this != &src)
	{
		year = src.year;
		month = src.month;
		day = src.day;
	}
	return *this;
}

bool BitcoinExchange::operator<(const BitcoinExchange& other) const {
	if (year != other.year) return year < other.year;
	if (month != other.month) return month < other.month;
	return day < other.day;
}

bool BitcoinExchange::operator==(const BitcoinExchange& other) const {
	if (year == other.year && month == other.month && day == other.day)
		return (true);
	return (false);
}

void	BitcoinExchange::findNearestValueInMap(const std::map<BitcoinExchange, float> &btcDataBase, float bitcoinNbr){
	// BitcoinExchange temp(*this);

	// while (btcDataBase.find(temp) == btcDataBase.end())
	// {
	// 	temp.setDay(temp.getDay() - 1);
	// 	if (temp.getDay() < 0){
	// 		temp.setDay(31);
	// 		temp.setMonth(temp.getMonth() - 1);
	// 		if (temp.getMonth() < 0){
	// 			temp.setMonth(12);
	// 			temp.setYear(temp.getYear() - 1);
	// 			if (temp.getYear() < btcDataBase.begin()->first.getYear())
	// 				throw std::runtime_error("Error: Bitcoin don't exist at this BitcoinExchange");
	// 		}
	// 	}
	// }
	// if (btcDataBase.find(temp) == btcDataBase.end())
	// 	throw std::runtime_error("Error: Bitcoin don't exist at this BitcoinExchange");

	std::map<BitcoinExchange, float>::const_iterator it = btcDataBase.upper_bound(*this);
	if (it == btcDataBase.begin()) {
        throw std::runtime_error("Error: Bitcoin don't exist at this BitcoinExchange");
    }
    --it;
	std::cout << *this << " => " << bitcoinNbr << " = " << bitcoinNbr * it->second<< std::endl;

}

void	BitcoinExchange::setYear(int _new_year){
	year = _new_year;
}

void	BitcoinExchange::setMonth(int _new_month){
	month = _new_month;
}

void	BitcoinExchange::setDay(int _new_day){
	day = _new_day;
}

int	BitcoinExchange::getYear(void) const{
	return (year);
}

int	BitcoinExchange::getMonth(void) const{
	return (month);
}

int	BitcoinExchange::getDay(void) const{
	return (day);
}

std::ostream& operator<<(std::ostream& os, const BitcoinExchange& obj) {
	os << obj.getYear() << "-" << obj.getMonth() << "-" << obj.getDay();
	return os;
}