/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 12:11:15 by jdhallen          #+#    #+#             */
/*   Updated: 2025/04/08 15:03:12 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

//FException
FException::FException(const std::string &_message): message(_message){
}

const char *FException::what(void) const throw(){
	return (message.c_str());
}

FException::~FException(void) throw(){
}

//GradeTooHighException

Form::GradeTooHighException::GradeTooHighException(void): FException("Form Grade is too high !"){
}

Form::GradeTooHighException::~GradeTooHighException(void) throw(){
}

//GradeTooLowException

Form::GradeTooLowException::GradeTooLowException(void): FException("Form Grade is too low !"){
}

Form::GradeTooLowException::~GradeTooLowException(void) throw(){
}


//Form
Form::Form(void): name("Random Form"), grade_to_sign(150), grade_to_exec(150){
}

Form::Form(std::string _name, int _grade_to_sign, int _grade_to_exec)
	: name(_name), grade_to_sign(_grade_to_sign), grade_to_exec(_grade_to_exec), is_signed(false){
	if (grade_to_sign < 1 || grade_to_exec < 1)
		throw GradeTooHighException();
	if (grade_to_sign > 150 || grade_to_exec > 150)
		throw GradeTooLowException();
}

Form::~Form(void){	
}

Form::Form(const Form &copy)
	: name(copy.name), grade_to_sign(copy.grade_to_sign), grade_to_exec(copy.grade_to_exec){
	*this = copy;
}

Form &Form::operator=(const Form &src){
	if (this != &src)
		this->is_signed = src.is_signed;
	return (*this);
}

const std::string	Form::getName(void){
	return (name);
}

int	Form::getGradeToSign(void){
	return (grade_to_sign);
}

int	Form::getGradeToExec(void){
	return (grade_to_exec);
}

bool	Form::getIsSigned(void){
	return (is_signed);
}

std::ostream& operator<<(std::ostream& output, Form& obj){
	output << obj.getName() << ",";
	if (obj.getIsSigned())
		output << " is signed ";
	else
		output << " is not signed";
	output << ", the grade to sign is " << obj.getGradeToSign();
	output << " and the grade to exec is " << obj.getGradeToExec() << ". ";
	return (output);
}
