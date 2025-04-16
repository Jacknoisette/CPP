/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 09:44:30 by codespace         #+#    #+#             */
/*   Updated: 2025/04/16 15:14:00 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

std::string getYear(const std::string &line, const  std::string &filename){
	std::string year;
	year = line.substr(0, 4);
	for (unsigned int i = 0; i < year.size(); i++)
		if (!std::isdigit(year[i]))
			throw std::runtime_error("Error: corrupted information in " + filename);
	if (line[4] != '-')
		throw std::runtime_error("Error: corrupted information in " + filename);
	return (year);
}

std::string getMonth(const std::string &line, const  std::string &filename){
	std::string month;
	
	month = line.substr(5, 2);
	for (unsigned int i = 0; i < month.size(); i++)
		if (!std::isdigit(month[i]))
			throw std::runtime_error("Error: corrupted information in " + filename);
	if (line[7] != '-')
		throw std::runtime_error("Error: corrupted information in " + filename);
	return (month);
}

std::string getDay(const std::string &line, const  std::string &filename, bool input){
	std::string day;
	
	day = line.substr(8, 2);
	for (unsigned int i = 0; i < day.size(); i++)
		if (!std::isdigit(day[i]))
			throw std::runtime_error("Error: corrupted information in " + filename);
	if (input == false){
		if (line[10] != ',')
			throw std::runtime_error("Error: corrupted information in " + filename);
	}
	else {
		if (line[10] != ' ' && line[11] != '|' && line[12] != ' ')
			throw std::runtime_error("Error: corrupted information in " + filename);
	}
	return (day);
}

float getFloatValue(const std::string &line, const  std::string &filename, bool input){
	std::string value;
	float 		float_value;
	
	if (input == false)
		value = line.substr(11, line.size() - 11);
	else
		value = line.substr(13, line.size() - 13);
	for (unsigned int i = 0; i < value.size(); i++)
		if (!std::isdigit(value[i]) && value[i] != '.' && value[i] != '+' && value[i] != '-')
			throw std::runtime_error("Error: corrupted information in " + filename);
	float_value = std::atof(value.c_str());
	if (float_value < 0){
		throw std::runtime_error("Error: not a positive number in " + filename);
	}
	if (input == false){
		if (float_value < std::numeric_limits<int>::min() || float_value > std::numeric_limits<int>::max())
			throw std::runtime_error("Error: too large number in " + filename);
	}
	else {
		if (float_value > 1000)
			throw std::runtime_error("Error: too large number in " + filename);
	}
	return (float_value);
}

Date createDate(const std::string &year, const std::string &month, const std::string &day, const std::string &filename)
{
	int	dayAMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int	dayAMonth_leapYear[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	Date		NewEntry;
	
	NewEntry.setYear(std::atoi(year.c_str()));
	NewEntry.setMonth(std::atoi(month.c_str()));
	if (NewEntry.getMonth() < 0 || NewEntry.getMonth() > 12)
		throw std::runtime_error("Error: bad input => " + year + "-" + month + "-" + day + " in " + filename);
	NewEntry.setDay(std::atoi(day.c_str()));
	if (NewEntry.getYear() % 4 == 0){
		if (NewEntry.getDay() < 1 || NewEntry.getDay() > dayAMonth_leapYear[NewEntry.getMonth() - 1])
			throw std::runtime_error("Error: bad input => " + year + "-" + month + "-" + day + " in " + filename);
	}
	else {
		if (NewEntry.getDay() < 1 || NewEntry.getDay() > dayAMonth[NewEntry.getMonth() - 1])
			throw std::runtime_error("Error: bad input => " + year + "-" + month + "-" + day + " in " + filename);
	}
	return (NewEntry);
}

int	getDataBaseInfo(std::map<Date, float> *btcDataBase, std::string filename){
	std::ifstream fd1(filename.c_str());
	if (!fd1){
		std::cout << "Error: with csv file" << std::endl;
		return (-1);
	}
	std::string line;
	std::getline(fd1, line);
	while (std::getline(fd1, line)){
		if (line.size() < 11){
			std::cout << "Error: bad input => " << line << std::endl;
			return (-1);
		}
		try{
			std::string year(getYear(line, filename));
			std::string month(getMonth(line, filename));
			std::string day(getDay(line, filename, false));
			float		float_value(getFloatValue(line, filename, false));
			Date		NewEntry (createDate(year, month, day, filename));
			(*btcDataBase)[NewEntry] = float_value;
		} catch (std::runtime_error & e) {
			std::cout << e.what() << std::endl;
			return (-1);
		}
	}
	return (0);
}

int	getUserBtcInput(std::map<Date, float> *btcDataBase, std::string filename){
	std::ifstream fd1(filename.c_str());
	if (!fd1){
		std::cout << "Error: with input file" << std::endl;
		return (-1);
	}
	std::string line;
	std::getline(fd1, line);
	if (line != "date | value")
		return (std::cout << filename << " have wrong header" << std::endl, -1);
	while (std::getline(fd1, line)){
		if (line.size() < 13){
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}
		try{
			std::string year(getYear(line, filename));
			std::string month(getMonth(line, filename));
			std::string day(getDay(line, filename, true));
			float		float_value(getFloatValue(line, filename, true));
			Date		NewEntry (createDate(year, month, day, filename));
			NewEntry.findNearestValueInMap(*btcDataBase, float_value);
		} catch (std::runtime_error & e) {
			std::cout << e.what() << std::endl;
		}
	}
	return (0);
}

int main(int argc, char **argv)
{
	if (argc != 2)
		return (std::cout << "Wrong Arg" << std::endl, -1);
	std::string filename = "data.csv";
	std::string	input = argv[1];
	
	std::map<Date, float> btcDataBase;
	if (getDataBaseInfo(&btcDataBase, filename) == -1)
		return (-1);
	// std::map<Date, float>::iterator it;
	// for (it = btcDataBase.begin(); it != btcDataBase.end(); ++it) {
	// 	std::cout << it->first.getYear() << "-" << it->first.getMonth() << "-" << it->first.getDay();
	// 	std::cout << " -> " << it->second << std::endl;
	// }
	if (getUserBtcInput(&btcDataBase, input) == -1)
		return (-1);
}
