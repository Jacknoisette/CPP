/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 12:34:01 by jdhallen          #+#    #+#             */
/*   Updated: 2025/04/16 15:16:08 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

Date::Date(void) : year(0), month(0), day(0){

}

Date::Date(int _year, int _month, int _day) : year(_year), month(_month), day(_day){
}

Date::~Date(void){
}

Date::Date(const Date &cpy){
	*this = cpy;
}

Date &Date::operator=(const Date &src){
	if (this != &src)
	{
		year = src.year;
		month = src.month;
		day = src.day;
	}
	return *this;
}

bool Date::operator<(const Date& other) const {
	if (year != other.year) return year < other.year;
	if (month != other.month) return month < other.month;
	return day < other.day;
}

bool Date::operator==(const Date& other) const {
	if (year == other.year && month == other.month && day == other.day)
		return (true);
	return (false);
}

void	Date::findNearestValueInMap(const std::map<Date, float> &btcDataBase, float bitcoinNbr){
	Date temp(*this);

	while (btcDataBase.find(temp) == btcDataBase.end())
	{
		temp.setDay(temp.getDay() - 1);
		if (temp.getDay() < 0){
			temp.setDay(31);
			temp.setMonth(temp.getMonth() - 1);
			if (temp.getMonth() < 0){
				temp.setMonth(12);
				temp.setYear(temp.getYear() - 1);
				if (temp.getYear() < btcDataBase.begin()->first.getYear())
					throw std::runtime_error("Error: Bitcoin don't exist at this date");
			}
		}
	}
	if (btcDataBase.find(temp) == btcDataBase.end())
		throw std::runtime_error("Error: Bitcoin don't exist at this date");
	std::cout << *this << " => " << bitcoinNbr << " = " << bitcoinNbr * btcDataBase.find(temp)->second<< std::endl;

}

void	Date::setYear(int _new_year){
	year = _new_year;
}

void	Date::setMonth(int _new_month){
	month = _new_month;
}

void	Date::setDay(int _new_day){
	day = _new_day;
}

int	Date::getYear(void) const{
	return (year);
}

int	Date::getMonth(void) const{
	return (month);
}

int	Date::getDay(void) const{
	return (day);
}

std::ostream& operator<<(std::ostream& os, const Date& obj) {
	os << obj.getYear() << "-" << obj.getMonth() << "-" << obj.getDay();
	return os;
}