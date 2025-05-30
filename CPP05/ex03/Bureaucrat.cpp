/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 12:11:15 by jdhallen          #+#    #+#             */
/*   Updated: 2025/05/21 10:14:40 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

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
	if (grade < 1){
		grade = 1;
		throw GradeTooHighException();
	}
	if (grade > 150){
		grade = 150;
		throw GradeTooLowException();
	}
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

const std::string	Bureaucrat::getName(void) const{
	return (name);
}

int	Bureaucrat::getGrade(void) const{
	return (grade);
}

void	Bureaucrat::incrementGrade(int increment){
	if (grade - increment < 1)
		throw GradeTooHighException();
	if (grade - increment > 150)
		throw GradeTooLowException();
	grade -= increment;
}

void	Bureaucrat::decrementGrade(int decrement){
	if (grade + decrement < 1)
		throw GradeTooHighException();
	if (grade + decrement > 150)
		throw GradeTooLowException();
	grade += decrement;
}

void	Bureaucrat::signForm(AForm &form){
	form.beSigned(*this);
}

void	Bureaucrat::executeForm(AForm const &form){
	try {
		form.execute(*this);
		std::cout << getName() << " execute " << form.getName() << std::endl;
	} catch (std::runtime_error & e){
		throw (e);
	}	
}

std::ostream& operator<<(std::ostream& output, const Bureaucrat& obj){
	output << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ". ";
	return (output);
}
