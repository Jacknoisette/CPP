/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 08:10:09 by codespace         #+#    #+#             */
/*   Updated: 2025/04/11 08:54:27 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

int Data::data_nbr = 0;

Data::Data(void) : name("Random Data"), nbr(10){
	data_nbr++;
}

Data::Data(std::string _name, int _nbr) : name(_name), nbr(_nbr){
	data_nbr++;
}

Data::~Data(void){
	data_nbr--;
}

Data::Data(const Data &cpy) : nbr(cpy.nbr){
	data_nbr++;
	*this = cpy;
}

Data &Data::operator=(const Data &src){
	if (this != &src)
		this->name = src.name;
	return (*this);
}

std::string	Data::getName(void) const{
	return (name);
}

int	Data::getNbr(void) const{
	return (nbr);
}

std::ostream& operator<<(std::ostream& os, const Data& obj){
	os << "Data: name " << obj.getName() << ", nbr " << obj.getNbr() << ". Total Data nbr : " << Data::data_nbr;
	return (os);
}