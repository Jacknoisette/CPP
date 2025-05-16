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

Form::GradeTooHighException::GradeTooHighException(std::string message): FException(message + " is too high !"){
}

Form::GradeTooHighException::~GradeTooHighException(void) throw(){
}

//GradeTooLowException

Form::GradeTooLowException::GradeTooLowException(std::string message): FException(message + " is too low !"){
}

Form::GradeTooLowException::~GradeTooLowException(void) throw(){
}


//Form
Form::Form(void): name("Random Form"), grade_to_sign(150), grade_to_exec(150), is_signed(false){
}

Form::Form(std::string _name, int _grade_to_sign, int _grade_to_exec)
	: name(_name), grade_to_sign(_grade_to_sign), grade_to_exec(_grade_to_exec), is_signed(false){
	if (grade_to_sign < 1)
		throw GradeTooHighException("Form grade to sign");
	if (grade_to_exec < 1)
		throw GradeTooHighException("Form grade to execute");
	if (grade_to_sign > 150)
		throw GradeTooLowException("Form grade to sign");
	if (grade_to_exec > 150)
		throw GradeTooLowException("Form grade to execute");
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

const std::string	Form::getName(void) const{
	return (name);
}

int	Form::getGradeToSign(void) const{
	return (grade_to_sign);
}

int	Form::getGradeToExec(void) const{
	return (grade_to_exec);
}

bool	Form::getIsSigned(void) const{
	return (is_signed);
}

void	Form::beSigned(Bureaucrat &executor){
	if (executor.getGrade() > this->getGradeToSign())
		throw GradeTooLowException("Bureaucrat " + executor.getName() + " grade to sign");
	if (!this->getIsSigned())
	{
		this->is_signed = true;
		std::cout << executor.getName() << " signed " << this->getName() << std::endl;
	}
	else
		std::cout << executor.getName() << " couldn't sign " << this->getName() << " because it was already sign !" <<  std::endl;
}

std::ostream& operator<<(std::ostream& output, const Form& obj){
	output << obj.getName() << ",";
	if (obj.getIsSigned())
		output << " is signed ";
	else
		output << " is not signed";
	output << ", the grade to sign is " << obj.getGradeToSign();
	output << " and the grade to exec is " << obj.getGradeToExec() << ". ";
	return (output);
}
