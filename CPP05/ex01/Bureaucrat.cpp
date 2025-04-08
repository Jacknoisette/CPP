/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 12:11:15 by jdhallen          #+#    #+#             */
/*   Updated: 2025/04/08 15:25:24 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

//BExeption
BException::BException(const std::string &_message): message(_message){
}

const char *BException::what(void) const throw(){
	return (message.c_str());
}

BException::~BException(void) throw(){
}

//GradeTooHighException

Bureaucrat::GradeTooHighException::GradeTooHighException(void): BException("Grade is too high !"){
}

Bureaucrat::GradeTooHighException::~GradeTooHighException(void) throw(){
}

//GradeTooLowException

Bureaucrat::GradeTooLowException::GradeTooLowException(void): BException("Grade is too low !"){
}

Bureaucrat::GradeTooLowException::~GradeTooLowException(void) throw(){
}


//Bureaucrat
Bureaucrat::Bureaucrat(void): name("Random Guy"), grade(150){
}

Bureaucrat::Bureaucrat(std::string _name, int _grade): name(_name), grade(_grade){
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::~Bureaucrat(void){	
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy): name(copy.name){
	*this = copy;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src){
	if (this != &src)
		this->grade = src.grade;
	return (*this);
}

const std::string	Bureaucrat::getName(void){
	return (name);
}

int	Bureaucrat::getGrade(void){
	return (grade);
}

void	Bureaucrat::incrementGrade(int increment){
	grade -= increment;
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

void	Bureaucrat::decrementGrade(int decrement){
	grade += decrement;
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& output, Bureaucrat& obj){
	output << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ". ";
	return (output);
}
